#include "logical_thread.h"
#include "gui/endurer_resources.h"
#include "gui/endurer_specifications.h"


#include "main_thread.h"
int direita;
int esquerda;
int geraInimigo;
int geraPista;
int score;
int restantes;
GX_VALUE level;
int acumulador;
int inimigoA;
int inimigoB;
int inimigoC;
int vento;
int dia;
int highscore;
/* Callback function */
void movimentaGeral(timer_callback_args_t *p_args)
{
    /* TODO: add your own code here */
    score +=level;
    geraInimigo++;
    geraPista++;
    g_timer.p_api->reset(g_timer.p_ctrl);
}

static void movimentacao(GX_RESOURCE_ID id, GX_VALUE movimentoX, GX_VALUE movimentoY);
void resetGame();
void gameOver();
void atualizaGui();
void geradorInimigos();
void geradorPista();
void atualizaScore(GX_RESOURCE_ID id, int atualizar);
int checaColisao(GX_RESOURCE_ID player, GX_RESOURCE_ID inimigo);
int ultrapassagem(GX_RESOURCE_ID player, GX_RESOURCE_ID inimigo);
void escondeIcon(GX_RESOURCE_ID id);
void mostraInimigo(GX_RESOURCE_ID id);
void diaNoite(GX_RESOURCE_ID id, int flipflop);
void resetGame();

/* Controle do Jogo entry function */
void logical_thread_entry(void)
{
    //STARTUP DE PARTIDA
    tx_mutex_get(&guixStarted, TX_WAIT_FOREVER);
    ULONG   received_message = 0;
    score = 0;
    inimigoA = 1;
    inimigoB = 0;
    inimigoC = 0;
    geraInimigo = 0;
    level = 1;
    restantes = 10;
    vento = 0;
    dia = 1;
    highscore = 0;
    acumulador = 0;
    g_timer.p_api->open(g_timer.p_ctrl, g_timer.p_cfg);
    g_timer.p_api->start(g_timer.p_ctrl);
    while (1)
    {

        tx_queue_receive(&g_input_queue, &received_message, TX_NO_WAIT);
        if(received_message == 1){
            direita = 1;
            received_message = 0;
        }
        if(received_message == 2){
            esquerda = 1;
            received_message = 0;
        }
        if(received_message == 3){
            resetGame();
            received_message = 0;
        }

        atualizaGui();
        tx_thread_sleep (3);
        gx_system_canvas_refresh();
    }
}



static void movimentacao(GX_RESOURCE_ID id, GX_VALUE movimentoX, GX_VALUE movimentoY){
    GX_ICON * p_icon = NULL;
    ssp_err_t err = (ssp_err_t)gx_system_widget_find((USHORT)id, GX_SEARCH_DEPTH_INFINITE, (GX_WIDGET**)&p_icon);
        if (TX_SUCCESS == err)
        {
            gx_widget_shift(p_icon, movimentoX, movimentoY, GX_TRUE);
        }
}


void atualizaGui()
{
    int flag = 0;
    int alfa = 0;
    if(inimigoA)
        movimentacao(ID_INIMIGO_A, (GX_VALUE) 0,level);
    if(inimigoB)
        movimentacao(ID_INIMIGO_B, (GX_VALUE) 0,level);
    if(inimigoC)
        movimentacao(ID_INIMIGO_C, (GX_VALUE) 0,level);

    if(direita){
        movimentacao(ID_CARRO, (GX_VALUE) -10,(GX_VALUE) 0);
        acumulador -=10;
        direita = 0;
    }
    if(esquerda){
        movimentacao(ID_CARRO, (GX_VALUE) 10,(GX_VALUE) 0);
        acumulador +=10;
        esquerda = 0;
    }
    movimentacao(ID_CARRO, (GX_VALUE) vento,(GX_VALUE) 0);
    acumulador+=vento;
    atualizaScore(ID_POINTS1, score);

    if(inimigoA)
        flag = checaColisao(ID_CARRO, ID_INIMIGO_A);
    if(flag){
        gameOver();
    }
    if(inimigoB)
        flag = checaColisao(ID_CARRO, ID_INIMIGO_B);
    if(flag){
        gameOver();
    }
    if(inimigoC)
        flag = checaColisao(ID_CARRO, ID_INIMIGO_C);
    if(flag){
        gameOver();
    }


    if(inimigoA){
        alfa = ultrapassagem(ID_CARRO, ID_INIMIGO_A);
        inimigoA -=alfa;
    }
    if(inimigoB){
        alfa = ultrapassagem(ID_CARRO, ID_INIMIGO_B);
        inimigoB -=alfa;
    }
    if(inimigoC){
        alfa = ultrapassagem(ID_CARRO, ID_INIMIGO_C);
        inimigoC -=alfa;
    }

    atualizaScore(ID_RACERS_LEFT, restantes);

    if(!restantes){
        restantes = 10;
        level++;
        dia = !dia;
        diaNoite(ID_INIMIGO_A, dia);
        diaNoite(ID_INIMIGO_B, dia);
        diaNoite(ID_INIMIGO_C, dia);
    }

    if(geraInimigo==4)
        geradorInimigos();
    if(geraPista==10)
        geradorPista();
}

void atualizaScore(GX_RESOURCE_ID id, int atualizar){
    GX_NUMERIC_PROMPT * p_icon = NULL;
    ssp_err_t err = (ssp_err_t)gx_system_widget_find((USHORT)id, GX_SEARCH_DEPTH_INFINITE, (GX_WIDGET**)&p_icon);
        if (TX_SUCCESS == err)
        {
            gx_numeric_prompt_value_set(p_icon, atualizar);
        }
}

int checaColisao(GX_RESOURCE_ID player, GX_RESOURCE_ID inimigo){
    GX_ICON * player_icon = NULL;
    GX_ICON * inimigo_icon = NULL;
    gx_system_widget_find((USHORT)player, GX_SEARCH_DEPTH_INFINITE, (GX_WIDGET**)&player_icon);
    gx_system_widget_find((USHORT)inimigo, GX_SEARCH_DEPTH_INFINITE, (GX_WIDGET**)&inimigo_icon);

    GX_VALUE topCarro, bottomCarro, leftCarro, rightCarro;
    topCarro = player_icon->gx_widget_size.gx_rectangle_top;
    leftCarro = player_icon->gx_widget_size.gx_rectangle_left;
    rightCarro = player_icon->gx_widget_size.gx_rectangle_right;
    bottomCarro = player_icon->gx_widget_size.gx_rectangle_bottom;


    GX_VALUE topInimigo, bottomInimigo, leftInimigo, rightInimigo;
    topInimigo = inimigo_icon->gx_widget_size.gx_rectangle_top;
    leftInimigo = inimigo_icon->gx_widget_size.gx_rectangle_left;
    rightInimigo = inimigo_icon->gx_widget_size.gx_rectangle_right;
    bottomInimigo = inimigo_icon->gx_widget_size.gx_rectangle_bottom;

    if(topCarro <= bottomInimigo && bottomCarro >= topInimigo && leftCarro <= rightInimigo && rightCarro >= leftInimigo){
        return 1;
    }
    return 0;
}
void resetGame(){
    g_timer.p_api->stop(g_timer.p_ctrl);
    score = 0;
    restantes = 10;
    level = 1;
    geraPista = 0;
    geraInimigo = 0;
    vento = 0;
    dia = 1;
    GX_ICON * p_icon = NULL;
    gx_system_widget_find(ID_CARRO, GX_SEARCH_DEPTH_INFINITE, (GX_WIDGET**)&p_icon);
    GX_VALUE corretor = (GX_VALUE) 108 - p_icon->gx_widget_size.gx_rectangle_top;
    movimentacao(ID_CARRO,corretor,0);
    gx_widget_show(p_icon);
    GX_ICON_BUTTON * p_but = NULL;
    gx_system_widget_find(ID_ESQUERDA, GX_SEARCH_DEPTH_INFINITE, (GX_WIDGET**)&p_but);
    gx_widget_show(p_but);
    gx_system_widget_find(ID_DIREITA, GX_SEARCH_DEPTH_INFINITE, (GX_WIDGET**)&p_but);
    gx_widget_show(p_but);
    inimigoA = 1;
    inimigoB = 0;
    inimigoC = 0;
    mostraInimigo(ID_INIMIGO_A);
    escondeIcon(ID_INIMIGO_B);
    escondeIcon(ID_INIMIGO_C);
    GX_WINDOW * p_win = NULL;
    gx_system_widget_find(ID_WINDOW1, GX_SEARCH_DEPTH_INFINITE, (GX_WIDGET**)&p_win);
    gx_window_wallpaper_set(p_win,GX_PIXELMAP_ID_DIA1,GX_FALSE);
    GX_PROMPT * p_prom = NULL;
    gx_system_widget_find((USHORT)ID_GAME_OVER, GX_SEARCH_DEPTH_INFINITE, (GX_WIDGET**)&p_prom);
    gx_prompt_text_id_set(p_prom, GX_STRING_ID_PARTIDA);
    g_timer.p_api->start(g_timer.p_ctrl);

}

void gameOver(){
    //apagar objetos de partida
    escondeIcon(ID_CARRO);
    escondeIcon(ID_INIMIGO_A);
    escondeIcon(ID_INIMIGO_B);
    escondeIcon(ID_INIMIGO_C);
    GX_ICON_BUTTON * p_but = NULL;
    gx_system_widget_find(ID_ESQUERDA, GX_SEARCH_DEPTH_INFINITE, (GX_WIDGET**)&p_but);
    gx_widget_hide(p_but);
    gx_system_widget_find(ID_DIREITA, GX_SEARCH_DEPTH_INFINITE, (GX_WIDGET**)&p_but);
    gx_widget_hide(p_but);
    if(score>highscore)
    {
        atualizaScore(ID_HIGHSCORE, score);
        highscore = score;
    }
    GX_PROMPT * p_prom = NULL;
    ssp_err_t err = (ssp_err_t)gx_system_widget_find((USHORT)ID_GAME_OVER, GX_SEARCH_DEPTH_INFINITE, (GX_WIDGET**)&p_prom);
    if (TX_SUCCESS == err)
    {
        gx_prompt_text_id_set(p_prom, GX_STRING_ID_GAME_OVER);
    }
    GX_WINDOW * p_win = NULL;
    gx_system_widget_find(ID_WINDOW1, GX_SEARCH_DEPTH_INFINITE, (GX_WIDGET**)&p_win);
    gx_window_wallpaper_set(p_win,GX_PIXELMAP_ID_NOITE,GX_TRUE);
}

int ultrapassagem(GX_RESOURCE_ID player, GX_RESOURCE_ID inimigo)
{
    GX_ICON * player_icon = NULL;
    GX_ICON * inimigo_icon = NULL;
    gx_system_widget_find((USHORT)player, GX_SEARCH_DEPTH_INFINITE, (GX_WIDGET**)&player_icon);
    gx_system_widget_find((USHORT)inimigo, GX_SEARCH_DEPTH_INFINITE, (GX_WIDGET**)&inimigo_icon);
    GX_VALUE carro, enemy;
    carro = player_icon->gx_widget_size.gx_rectangle_bottom;
    enemy = inimigo_icon->gx_widget_size.gx_rectangle_top;
    if(enemy>carro){
        gx_widget_hide(inimigo_icon);
        restantes--;
        return 1;
    }
    return 0;
}

void geradorInimigos() //A cada 2s gera um novo inimigo
{
    geraInimigo=0;
    int seed = score%3;
    if(!inimigoA && seed == 0){
        mostraInimigo(ID_INIMIGO_A);
        inimigoA=1;
        return;
    }
    if(!inimigoB && seed == 2){
        mostraInimigo(ID_INIMIGO_B);
        inimigoB=1;
        return;
    }
    if(!inimigoC){
        mostraInimigo(ID_INIMIGO_C);
        inimigoC=1;
        return;
    }

}
void geradorPista(){ //A cada 5s gera um novo formato de pista
    geraPista=0;
    vento=0;
    int seed = rand()%3;
    GX_WINDOW * p_win = NULL;
    gx_system_widget_find(ID_WINDOW1, GX_SEARCH_DEPTH_INFINITE, (GX_WIDGET**)&p_win);
    if(seed==0){
        if(dia)
        {
            gx_window_wallpaper_set(p_win,GX_PIXELMAP_ID_DIA1,GX_FALSE);
        }
        else
        {
            gx_window_wallpaper_set(p_win,GX_PIXELMAP_ID_NOITE1,GX_FALSE);
        }

    }
    if(seed==1){
        vento = +level;
        if(dia)
            {
                gx_window_wallpaper_set(p_win,GX_PIXELMAP_ID_DIA2,GX_FALSE);
            }
            else
            {
                gx_window_wallpaper_set(p_win,GX_PIXELMAP_ID_NOITE2,GX_FALSE);
            }
    }
    if(seed==2){
        vento = -level;
        if(dia)
            {
                gx_window_wallpaper_set(p_win,GX_PIXELMAP_ID_DIA3,GX_FALSE);
            }
            else
            {
                gx_window_wallpaper_set(p_win,GX_PIXELMAP_ID_NOITE3,GX_FALSE);
            }
    }
}
void escondeIcon(GX_RESOURCE_ID id){
    GX_ICON * p_icon = NULL;
        ssp_err_t err = (ssp_err_t)gx_system_widget_find((USHORT)id, GX_SEARCH_DEPTH_INFINITE, (GX_WIDGET**)&p_icon);
            if (TX_SUCCESS == err)
            {
                gx_widget_hide(p_icon);
            }
}
void mostraInimigo(GX_RESOURCE_ID id){
    GX_ICON * p_icon = NULL;
        ssp_err_t err = (ssp_err_t)gx_system_widget_find((USHORT)id, GX_SEARCH_DEPTH_INFINITE, (GX_WIDGET**)&p_icon);
            if (TX_SUCCESS == err)
            {
                GX_VALUE corretor = (GX_VALUE)83 - p_icon->gx_widget_size.gx_rectangle_top;
                movimentacao(id,0,corretor);
                gx_widget_show(p_icon);
            }
}
void diaNoite(GX_RESOURCE_ID id, int flipflop){
    GX_ICON * p_icon = NULL;
    ssp_err_t err = (ssp_err_t)gx_system_widget_find((USHORT)id, GX_SEARCH_DEPTH_INFINITE, (GX_WIDGET**)&p_icon);
    if (TX_SUCCESS == err)
    {
        if(flipflop)
        {
            gx_icon_pixelmap_set(p_icon,GX_PIXELMAP_ID_INIMIGONOITE,GX_PIXELMAP_ID_INIMIGONOITE);
        }
        else
        {
            gx_icon_pixelmap_set(p_icon,GX_PIXELMAP_ID_INIMIGO,GX_PIXELMAP_ID_INIMIGO);
        }
    }
}
