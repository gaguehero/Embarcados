/*******************************************************************************/
/*  This file is auto-generated by GUIX Studio. Do not edit this file by hand. */
/*  Modifications to this file should only be made by running the GUIX Studio  */
/*  application and re-generating the application. For more information please */
/*  refer to the GUIX Studio user's guide, or visit our web site at            */
/*  www.expresslogic.com.                                                      */
/*                                                                             */
/*  GUIX Studio Revision 5.6.1.0                                               */
/*  Date (dd.mm.yyyy): 24. 5.2021   Time (hh:mm): 05:39                        */
/*******************************************************************************/


#define GUIX_STUDIO_GENERATED_FILE
#include <stddef.h>
#include "endurer_resources.h"
#include "endurer_specifications.h"

static GX_WIDGET *gx_studio_nested_widget_create(GX_BYTE *control, GX_CONST GX_STUDIO_WIDGET *definition, GX_WIDGET *parent);
WINDOW1_CONTROL_BLOCK window1;
GX_DISPLAY display_1_control_block;
GX_WINDOW_ROOT display_1_root_window;
GX_CANVAS  display_1_canvas_control_block;
ULONG      display_1_canvas_memory[40960];

extern GX_CONST GX_THEME *display_1_theme_table[];
extern GX_CONST GX_STRING *display_1_language_table[];

GX_STUDIO_DISPLAY_INFO endurer_display_table[1] =
{
    {
    "display_1",
    "display_1_canvas",
    display_1_theme_table,
    display_1_language_table,
    DISPLAY_1_THEME_TABLE_SIZE,
    DISPLAY_1_LANGUAGE_TABLE_SIZE,
    DISPLAY_1_STRING_TABLE_SIZE,
    256,                                     /* x resolution                   */
    320,                                     /* y resolution                   */
    &display_1_control_block,
    &display_1_canvas_control_block,
    &display_1_root_window,
    display_1_canvas_memory,                 /* canvas memory area             */
    163840                                   /* canvas memory size in bytes    */
    }
};


UINT gx_studio_icon_button_create(GX_CONST GX_STUDIO_WIDGET *info, GX_WIDGET *control_block, GX_WIDGET *parent)
{
    UINT status;
    GX_ICON_BUTTON *button = (GX_ICON_BUTTON *) control_block;
    GX_ICON_BUTTON_PROPERTIES *props = (GX_ICON_BUTTON_PROPERTIES *) info->properties;
    status = gx_icon_button_create(button, info->widget_name, parent, props->pixelmap_id, info->style, info->widget_id, &info->size);
    return status;
}

UINT gx_studio_icon_create(GX_CONST GX_STUDIO_WIDGET *info, GX_WIDGET *control_block, GX_WIDGET *parent)
{
    UINT status;
    GX_ICON *icon = (GX_ICON *) control_block;
    GX_ICON_PROPERTIES *props = (GX_ICON_PROPERTIES *) info->properties;
    status = gx_icon_create(icon, info->widget_name, parent, props->normal_pixelmap_id, info->style, info->widget_id, info->size.gx_rectangle_left, info->size.gx_rectangle_top);
    if (props->selected_pixelmap_id)
    {
        gx_icon_pixelmap_set(icon, props->normal_pixelmap_id, props->selected_pixelmap_id);
    }
    return status;
}

UINT gx_studio_prompt_create(GX_CONST GX_STUDIO_WIDGET *info, GX_WIDGET *control_block, GX_WIDGET *parent)
{
    UINT status;
    GX_PROMPT *prompt = (GX_PROMPT *) control_block;
    GX_PROMPT_PROPERTIES *props = (GX_PROMPT_PROPERTIES *) info->properties;
    status = gx_prompt_create(prompt, info->widget_name, parent, props->string_id, info->style, info->widget_id, &info->size);
    if (status == GX_SUCCESS)
    {
        gx_prompt_font_set(prompt, props->font_id);
#if defined(GUIX_5_4_0_COMPATIBILITY)
        gx_prompt_text_color_set(prompt, props->normal_text_color_id, props->selected_text_color_id);
#else
        gx_prompt_text_color_set(prompt, props->normal_text_color_id, props->selected_text_color_id, props->disabled_text_color_id);
#endif
    }
    return status;
}

UINT gx_studio_numeric_prompt_create(GX_CONST GX_STUDIO_WIDGET *info, GX_WIDGET *control_block, GX_WIDGET *parent)
{
    UINT status;
    GX_NUMERIC_PROMPT *prompt = (GX_NUMERIC_PROMPT *) control_block;
    GX_NUMERIC_PROMPT_PROPERTIES *props = (GX_NUMERIC_PROMPT_PROPERTIES *) info->properties;
    status = gx_numeric_prompt_create(prompt, info->widget_name, parent, props->string_id, info->style, info->widget_id, &info->size);
    if (status == GX_SUCCESS)
    {
        gx_prompt_font_set((GX_PROMPT *)prompt, props->font_id);
#if defined(GUIX_5_4_0_COMPATIBILITY)
        gx_prompt_text_color_set((GX_PROMPT *)prompt, props->normal_text_color_id, props->selected_text_color_id);
#else
        gx_prompt_text_color_set((GX_PROMPT *)prompt, props->normal_text_color_id, props->selected_text_color_id, props->disabled_text_color_id);
#endif
        if(!props->string_id)
        {
            gx_numeric_prompt_value_set(prompt, props->numeric_prompt_value);
        }
        if(props->format_func)
        {
            gx_numeric_prompt_format_function_set(prompt, props->format_func);
        }
    }
    return status;
}

UINT gx_studio_window_create(GX_CONST GX_STUDIO_WIDGET *info, GX_WIDGET *control_block, GX_WIDGET *parent)
{
    UINT status;
    GX_WINDOW *window = (GX_WINDOW *) control_block;
    GX_WINDOW_PROPERTIES *props = (GX_WINDOW_PROPERTIES *) info->properties;
    status = gx_window_create(window, info->widget_name, parent, info->style, info->widget_id, &info->size);
    if (status == GX_SUCCESS)
    {
        if (props->wallpaper_id)
        {
            gx_window_wallpaper_set(window, props->wallpaper_id, info->style & GX_STYLE_TILE_WALLPAPER);
        }
    }
    return status;
}
GX_WINDOW_PROPERTIES window1_properties =
{
    GX_PIXELMAP_ID_DIA1                      /* wallpaper pixelmap id          */
};
GX_ICON_BUTTON_PROPERTIES window1_direita_properties =
{
    GX_PIXELMAP_ID_DIREITA                   /* pixelmap id                    */
};
GX_ICON_BUTTON_PROPERTIES window1_esquerda_properties =
{
    GX_PIXELMAP_ID_ESQUERDA                  /* pixelmap id                    */
};
GX_ICON_PROPERTIES window1_carro_properties =
{
    GX_PIXELMAP_ID_CARRO,                    /* normal pixelmap id             */
    0                                        /* selected pixelmap id           */
};
GX_ICON_PROPERTIES window1_inimigoA_properties =
{
    GX_PIXELMAP_ID_INIMIGO,                  /* normal pixelmap id             */
    0                                        /* selected pixelmap id           */
};
GX_NUMERIC_PROMPT_PROPERTIES window1_highscore_properties =
{
    0,                                       /* string id                      */
    GX_FONT_ID_PROMPT,                       /* font id                        */
    GX_COLOR_ID_TEXT,                        /* normal text color              */
    GX_COLOR_ID_SELECTED_TEXT,               /* selected text color            */
    GX_COLOR_ID_DISABLED_TEXT,               /* disabled text color            */
    GX_NULL,                                 /* format function                */
    0                                        /* numeric prompt value           */
};
GX_NUMERIC_PROMPT_PROPERTIES window1_racers_remaining_properties =
{
    0,                                       /* string id                      */
    GX_FONT_ID_PROMPT,                       /* font id                        */
    GX_COLOR_ID_TEXT,                        /* normal text color              */
    GX_COLOR_ID_SELECTED_TEXT,               /* selected text color            */
    GX_COLOR_ID_DISABLED_TEXT,               /* disabled text color            */
    GX_NULL,                                 /* format function                */
    0                                        /* numeric prompt value           */
};
GX_NUMERIC_PROMPT_PROPERTIES window1_points_properties =
{
    0,                                       /* string id                      */
    GX_FONT_ID_PROMPT,                       /* font id                        */
    GX_COLOR_ID_TEXT,                        /* normal text color              */
    GX_COLOR_ID_SELECTED_TEXT,               /* selected text color            */
    GX_COLOR_ID_DISABLED_TEXT,               /* disabled text color            */
    GX_NULL,                                 /* format function                */
    0                                        /* numeric prompt value           */
};
GX_ICON_BUTTON_PROPERTIES window1_reset_properties =
{
    GX_PIXELMAP_ID_RESTART                   /* pixelmap id                    */
};
GX_PROMPT_PROPERTIES window1_game_over_properties =
{
    GX_STRING_ID_PARTIDA,                    /* string id                      */
    GX_FONT_ID_PROMPT,                       /* font id                        */
    GX_COLOR_ID_TEXT_INPUT_TEXT,             /* normal text color              */
    GX_COLOR_ID_SELECTED_TEXT,               /* selected text color            */
    GX_COLOR_ID_DISABLED_TEXT                /* disabled text color            */
};
GX_ICON_PROPERTIES window1_inimigoB_properties =
{
    GX_PIXELMAP_ID_INIMIGO,                  /* normal pixelmap id             */
    0                                        /* selected pixelmap id           */
};
GX_ICON_PROPERTIES window1_inimigoC_properties =
{
    GX_PIXELMAP_ID_INIMIGO,                  /* normal pixelmap id             */
    0                                        /* selected pixelmap id           */
};

GX_CONST GX_STUDIO_WIDGET window1_inimigoC_define =
{
    "inimigoC",
    GX_TYPE_ICON,                            /* widget type                    */
    ID_INIMIGO_C,                            /* widget id                      */
    #if defined(GX_WIDGET_USER_DATA)
    0,                                       /* user data                      */
    #endif
    GX_STYLE_BORDER_NONE|GX_STYLE_ENABLED|GX_STYLE_HALIGN_LEFT|GX_STYLE_VALIGN_TOP,   /* style flags */
    GX_STATUS_ACCEPTS_FOCUS,                 /* status flags                   */
    sizeof(GX_ICON),                         /* control block size             */
    GX_COLOR_ID_WIDGET_FILL,                 /* normal color id                */
    GX_COLOR_ID_SELECTED_FILL,               /* selected color id              */
    GX_COLOR_ID_DISABLED_FILL,               /* disabled color id              */
    gx_studio_icon_create,                   /* create function                */
    GX_NULL,                                 /* drawing function override      */
    GX_NULL,                                 /* event function override        */
    {159, 83, 174, 98},                      /* widget size                    */
    GX_NULL,                                 /* no next widget                 */
    GX_NULL,                                 /* no child widgets               */ 
    offsetof(WINDOW1_CONTROL_BLOCK, window1_inimigoC), /* control block        */
    (void *) &window1_inimigoC_properties    /* extended properties            */
};

GX_CONST GX_STUDIO_WIDGET window1_inimigoB_define =
{
    "inimigoB",
    GX_TYPE_ICON,                            /* widget type                    */
    ID_INIMIGO_B,                            /* widget id                      */
    #if defined(GX_WIDGET_USER_DATA)
    0,                                       /* user data                      */
    #endif
    GX_STYLE_BORDER_NONE|GX_STYLE_ENABLED|GX_STYLE_HALIGN_LEFT|GX_STYLE_VALIGN_TOP,   /* style flags */
    GX_STATUS_ACCEPTS_FOCUS,                 /* status flags                   */
    sizeof(GX_ICON),                         /* control block size             */
    GX_COLOR_ID_WIDGET_FILL,                 /* normal color id                */
    GX_COLOR_ID_SELECTED_FILL,               /* selected color id              */
    GX_COLOR_ID_DISABLED_FILL,               /* disabled color id              */
    gx_studio_icon_create,                   /* create function                */
    GX_NULL,                                 /* drawing function override      */
    GX_NULL,                                 /* event function override        */
    {65, 83, 80, 98},                        /* widget size                    */
    &window1_inimigoC_define,                /* next widget definition         */
    GX_NULL,                                 /* no child widgets               */ 
    offsetof(WINDOW1_CONTROL_BLOCK, window1_inimigoB), /* control block        */
    (void *) &window1_inimigoB_properties    /* extended properties            */
};

GX_CONST GX_STUDIO_WIDGET window1_game_over_define =
{
    "game_over",
    GX_TYPE_PROMPT,                          /* widget type                    */
    ID_GAME_OVER,                            /* widget id                      */
    #if defined(GX_WIDGET_USER_DATA)
    0,                                       /* user data                      */
    #endif
    GX_STYLE_BORDER_NONE|GX_STYLE_TRANSPARENT|GX_STYLE_ENABLED|GX_STYLE_TEXT_CENTER,   /* style flags */
    GX_STATUS_ACCEPTS_FOCUS,                 /* status flags                   */
    sizeof(GX_PROMPT),                       /* control block size             */
    GX_COLOR_ID_TEXT_INPUT_FILL,             /* normal color id                */
    GX_COLOR_ID_SELECTED_FILL,               /* selected color id              */
    GX_COLOR_ID_DISABLED_FILL,               /* disabled color id              */
    gx_studio_prompt_create,                 /* create function                */
    GX_NULL,                                 /* drawing function override      */
    GX_NULL,                                 /* event function override        */
    {64, 83, 183, 106},                      /* widget size                    */
    &window1_inimigoB_define,                /* next widget definition         */
    GX_NULL,                                 /* no child widgets               */ 
    offsetof(WINDOW1_CONTROL_BLOCK, window1_game_over), /* control block       */
    (void *) &window1_game_over_properties   /* extended properties            */
};

GX_CONST GX_STUDIO_WIDGET window1_reset_define =
{
    "reset",
    GX_TYPE_ICON_BUTTON,                     /* widget type                    */
    ID_RESET1,                               /* widget id                      */
    #if defined(GX_WIDGET_USER_DATA)
    0,                                       /* user data                      */
    #endif
    GX_STYLE_BORDER_NONE|GX_STYLE_TRANSPARENT|GX_STYLE_ENABLED|GX_STYLE_HALIGN_CENTER|GX_STYLE_VALIGN_CENTER,   /* style flags */
    GX_STATUS_ACCEPTS_FOCUS,                 /* status flags                   */
    sizeof(GX_ICON_BUTTON),                  /* control block size             */
    GX_COLOR_ID_BTN_LOWER,                   /* normal color id                */
    GX_COLOR_ID_BTN_UPPER,                   /* selected color id              */
    GX_COLOR_ID_DISABLED_FILL,               /* disabled color id              */
    gx_studio_icon_button_create,            /* create function                */
    GX_NULL,                                 /* drawing function override      */
    GX_NULL,                                 /* event function override        */
    {2, 2, 65, 65},                          /* widget size                    */
    &window1_game_over_define,               /* next widget definition         */
    GX_NULL,                                 /* no child widgets               */ 
    offsetof(WINDOW1_CONTROL_BLOCK, window1_reset), /* control block           */
    (void *) &window1_reset_properties       /* extended properties            */
};

GX_CONST GX_STUDIO_WIDGET window1_points_define =
{
    "points",
    GX_TYPE_NUMERIC_PROMPT,                  /* widget type                    */
    ID_POINTS1,                              /* widget id                      */
    #if defined(GX_WIDGET_USER_DATA)
    0,                                       /* user data                      */
    #endif
    GX_STYLE_BORDER_THIN|GX_STYLE_ENABLED|GX_STYLE_TEXT_CENTER,   /* style flags */
    GX_STATUS_ACCEPTS_FOCUS,                 /* status flags                   */
    sizeof(GX_NUMERIC_PROMPT),               /* control block size             */
    GX_COLOR_ID_WIDGET_FILL,                 /* normal color id                */
    GX_COLOR_ID_SELECTED_FILL,               /* selected color id              */
    GX_COLOR_ID_DISABLED_FILL,               /* disabled color id              */
    gx_studio_numeric_prompt_create,         /* create function                */
    GX_NULL,                                 /* drawing function override      */
    GX_NULL,                                 /* event function override        */
    {79, 289, 158, 312},                     /* widget size                    */
    &window1_reset_define,                   /* next widget definition         */
    GX_NULL,                                 /* no child widgets               */ 
    offsetof(WINDOW1_CONTROL_BLOCK, window1_points), /* control block          */
    (void *) &window1_points_properties      /* extended properties            */
};

GX_CONST GX_STUDIO_WIDGET window1_racers_remaining_define =
{
    "racers_remaining",
    GX_TYPE_NUMERIC_PROMPT,                  /* widget type                    */
    ID_RACERS_LEFT,                          /* widget id                      */
    #if defined(GX_WIDGET_USER_DATA)
    0,                                       /* user data                      */
    #endif
    GX_STYLE_BORDER_THIN|GX_STYLE_ENABLED|GX_STYLE_TEXT_CENTER,   /* style flags */
    GX_STATUS_ACCEPTS_FOCUS,                 /* status flags                   */
    sizeof(GX_NUMERIC_PROMPT),               /* control block size             */
    GX_COLOR_ID_WIDGET_FILL,                 /* normal color id                */
    GX_COLOR_ID_SELECTED_FILL,               /* selected color id              */
    GX_COLOR_ID_DISABLED_FILL,               /* disabled color id              */
    gx_studio_numeric_prompt_create,         /* create function                */
    GX_NULL,                                 /* drawing function override      */
    GX_NULL,                                 /* event function override        */
    {79, 253, 158, 276},                     /* widget size                    */
    &window1_points_define,                  /* next widget definition         */
    GX_NULL,                                 /* no child widgets               */ 
    offsetof(WINDOW1_CONTROL_BLOCK, window1_racers_remaining), /* control block */
    (void *) &window1_racers_remaining_properties /* extended properties       */
};

GX_CONST GX_STUDIO_WIDGET window1_highscore_define =
{
    "highscore",
    GX_TYPE_NUMERIC_PROMPT,                  /* widget type                    */
    ID_HIGHSCORE,                            /* widget id                      */
    #if defined(GX_WIDGET_USER_DATA)
    0,                                       /* user data                      */
    #endif
    GX_STYLE_BORDER_THIN|GX_STYLE_ENABLED|GX_STYLE_TEXT_CENTER,   /* style flags */
    GX_STATUS_ACCEPTS_FOCUS,                 /* status flags                   */
    sizeof(GX_NUMERIC_PROMPT),               /* control block size             */
    GX_COLOR_ID_WIDGET_FILL,                 /* normal color id                */
    GX_COLOR_ID_SELECTED_FILL,               /* selected color id              */
    GX_COLOR_ID_DISABLED_FILL,               /* disabled color id              */
    gx_studio_numeric_prompt_create,         /* create function                */
    GX_NULL,                                 /* drawing function override      */
    GX_NULL,                                 /* event function override        */
    {158, 2, 237, 25},                       /* widget size                    */
    &window1_racers_remaining_define,        /* next widget definition         */
    GX_NULL,                                 /* no child widgets               */ 
    offsetof(WINDOW1_CONTROL_BLOCK, window1_highscore), /* control block       */
    (void *) &window1_highscore_properties   /* extended properties            */
};

GX_CONST GX_STUDIO_WIDGET window1_inimigoA_define =
{
    "inimigoA",
    GX_TYPE_ICON,                            /* widget type                    */
    ID_INIMIGO_A,                            /* widget id                      */
    #if defined(GX_WIDGET_USER_DATA)
    0,                                       /* user data                      */
    #endif
    GX_STYLE_BORDER_NONE|GX_STYLE_ENABLED|GX_STYLE_HALIGN_LEFT|GX_STYLE_VALIGN_TOP,   /* style flags */
    GX_STATUS_ACCEPTS_FOCUS,                 /* status flags                   */
    sizeof(GX_ICON),                         /* control block size             */
    GX_COLOR_ID_WIDGET_FILL,                 /* normal color id                */
    GX_COLOR_ID_SELECTED_FILL,               /* selected color id              */
    GX_COLOR_ID_DISABLED_FILL,               /* disabled color id              */
    gx_studio_icon_create,                   /* create function                */
    GX_NULL,                                 /* drawing function override      */
    GX_NULL,                                 /* event function override        */
    {111, 83, 126, 98},                      /* widget size                    */
    &window1_highscore_define,               /* next widget definition         */
    GX_NULL,                                 /* no child widgets               */ 
    offsetof(WINDOW1_CONTROL_BLOCK, window1_inimigoA), /* control block        */
    (void *) &window1_inimigoA_properties    /* extended properties            */
};

GX_CONST GX_STUDIO_WIDGET window1_carro_define =
{
    "carro",
    GX_TYPE_ICON,                            /* widget type                    */
    ID_CARRO,                                /* widget id                      */
    #if defined(GX_WIDGET_USER_DATA)
    0,                                       /* user data                      */
    #endif
    GX_STYLE_BORDER_NONE|GX_STYLE_ENABLED|GX_STYLE_HALIGN_LEFT|GX_STYLE_VALIGN_TOP,   /* style flags */
    GX_STATUS_ACCEPTS_FOCUS,                 /* status flags                   */
    sizeof(GX_ICON),                         /* control block size             */
    GX_COLOR_ID_WIDGET_FILL,                 /* normal color id                */
    GX_COLOR_ID_SELECTED_FILL,               /* selected color id              */
    GX_COLOR_ID_DISABLED_FILL,               /* disabled color id              */
    gx_studio_icon_create,                   /* create function                */
    GX_NULL,                                 /* drawing function override      */
    GX_NULL,                                 /* event function override        */
    {108, 227, 123, 242},                    /* widget size                    */
    &window1_inimigoA_define,                /* next widget definition         */
    GX_NULL,                                 /* no child widgets               */ 
    offsetof(WINDOW1_CONTROL_BLOCK, window1_carro), /* control block           */
    (void *) &window1_carro_properties       /* extended properties            */
};

GX_CONST GX_STUDIO_WIDGET window1_esquerda_define =
{
    "esquerda",
    GX_TYPE_ICON_BUTTON,                     /* widget type                    */
    ID_ESQUERDA,                             /* widget id                      */
    #if defined(GX_WIDGET_USER_DATA)
    0,                                       /* user data                      */
    #endif
    GX_STYLE_BORDER_NONE|GX_STYLE_TRANSPARENT|GX_STYLE_ENABLED|GX_STYLE_HALIGN_CENTER|GX_STYLE_VALIGN_CENTER,   /* style flags */
    GX_STATUS_ACCEPTS_FOCUS,                 /* status flags                   */
    sizeof(GX_ICON_BUTTON),                  /* control block size             */
    GX_COLOR_ID_BTN_LOWER,                   /* normal color id                */
    GX_COLOR_ID_BTN_UPPER,                   /* selected color id              */
    GX_COLOR_ID_DISABLED_FILL,               /* disabled color id              */
    gx_studio_icon_button_create,            /* create function                */
    GX_NULL,                                 /* drawing function override      */
    GX_NULL,                                 /* event function override        */
    {2, 253, 65, 316},                       /* widget size                    */
    &window1_carro_define,                   /* next widget definition         */
    GX_NULL,                                 /* no child widgets               */ 
    offsetof(WINDOW1_CONTROL_BLOCK, window1_esquerda), /* control block        */
    (void *) &window1_esquerda_properties    /* extended properties            */
};

GX_CONST GX_STUDIO_WIDGET window1_direita_define =
{
    "direita",
    GX_TYPE_ICON_BUTTON,                     /* widget type                    */
    ID_DIREITA,                              /* widget id                      */
    #if defined(GX_WIDGET_USER_DATA)
    0,                                       /* user data                      */
    #endif
    GX_STYLE_BORDER_NONE|GX_STYLE_TRANSPARENT|GX_STYLE_ENABLED|GX_STYLE_HALIGN_CENTER|GX_STYLE_VALIGN_CENTER,   /* style flags */
    GX_STATUS_ACCEPTS_FOCUS,                 /* status flags                   */
    sizeof(GX_ICON_BUTTON),                  /* control block size             */
    GX_COLOR_ID_BTN_LOWER,                   /* normal color id                */
    GX_COLOR_ID_BTN_UPPER,                   /* selected color id              */
    GX_COLOR_ID_DISABLED_FILL,               /* disabled color id              */
    gx_studio_icon_button_create,            /* create function                */
    GX_NULL,                                 /* drawing function override      */
    GX_NULL,                                 /* event function override        */
    {173, 253, 236, 316},                    /* widget size                    */
    &window1_esquerda_define,                /* next widget definition         */
    GX_NULL,                                 /* no child widgets               */ 
    offsetof(WINDOW1_CONTROL_BLOCK, window1_direita), /* control block         */
    (void *) &window1_direita_properties     /* extended properties            */
};

GX_CONST GX_STUDIO_WIDGET window1_define =
{
    "window1",
    GX_TYPE_WINDOW,                          /* widget type                    */
    ID_WINDOW1,                              /* widget id                      */
    #if defined(GX_WIDGET_USER_DATA)
    0,                                       /* user data                      */
    #endif
    GX_STYLE_BORDER_NONE|GX_STYLE_ENABLED,   /* style flags                    */
    GX_STATUS_ACCEPTS_FOCUS,                 /* status flags                   */
    sizeof(WINDOW1_CONTROL_BLOCK),           /* control block size             */
    GX_COLOR_ID_TEXT,                        /* normal color id                */
    GX_COLOR_ID_WINDOW_FILL,                 /* selected color id              */
    GX_COLOR_ID_DISABLED_FILL,               /* disabled color id              */
    gx_studio_window_create,                 /* create function                */
    GX_NULL,                                 /* drawing function override      */
    (UINT (*)(GX_WIDGET *, GX_EVENT *)) window1_handler, /* event function override */
    {0, 0, 239, 319},                        /* widget size                    */
    GX_NULL,                                 /* next widget                    */
    &window1_direita_define,                 /* child widget                   */
    0,                                       /* control block                  */
    (void *) &window1_properties             /* extended properties            */
};
GX_CONST GX_STUDIO_WIDGET_ENTRY endurer_widget_table[] =
{
    { &window1_define, (GX_WIDGET *) &window1 },
    {GX_NULL, GX_NULL}
};

static GX_WIDGET *gx_studio_nested_widget_create(GX_BYTE *control, GX_CONST GX_STUDIO_WIDGET *definition, GX_WIDGET *parent)
{
    UINT status = GX_SUCCESS;
    GX_WIDGET *widget = GX_NULL;
    GX_VALUE   list_count = 0;
    GX_VALUE   list_total_count = 0;

    if(parent && (parent->gx_widget_type == GX_TYPE_MENU))
    {
        list_total_count = ((GX_MENU *)parent)->gx_menu_list_total_count;
    }

    while(definition && status == GX_SUCCESS)
    {
        if (definition->create_function)
        {
            if (definition->style & GX_STYLE_DYNAMICALLY_ALLOCATED)
            {
                status = gx_widget_allocate(&widget, definition->control_block_size);
                if (status != GX_SUCCESS)
                {
                    return GX_NULL;
                }
            }
            else
            {
                if (control == GX_NULL)
                {
                    return GX_NULL;
                }
                widget = (GX_WIDGET *) (control + definition->control_block_offset);
            }

            status = definition->create_function(definition, widget, parent);

            if(list_count < list_total_count)
            {
                gx_menu_insert((GX_MENU *)parent, widget);
                ((GX_MENU *)parent)->gx_menu_list_total_count--;
                list_count++;
            }

            if (status == GX_SUCCESS)
            {
                if (definition->widget_type != GX_TYPE_TEMPLATE)
                {
#if defined(GUIX_5_4_0_COMPATIBILITY)
                    gx_widget_fill_color_set(widget, definition->normal_fill_color_id, definition->selected_fill_color_id);
#else
                    gx_widget_fill_color_set(widget, definition->normal_fill_color_id, definition->selected_fill_color_id, definition->disabled_fill_color_id);
#endif
                }

                if (!(definition->status & GX_STATUS_ACCEPTS_FOCUS))
                {
                    gx_widget_status_remove(widget, GX_STATUS_ACCEPTS_FOCUS);
                }

                if (definition->draw_function)
                {
                    gx_widget_draw_set(widget, definition->draw_function);
                }
                if (definition->event_function)
                {
                    gx_widget_event_process_set(widget, definition->event_function);
                }

                #if defined(GX_WIDGET_USER_DATA)
                widget->gx_widget_user_data = definition->user_data;
                #endif

                if (definition->child_widget)
                {
                    gx_studio_nested_widget_create(control, definition->child_widget, widget);
                }
            }
            definition = definition->next_widget;
        }
    }
    return widget;
}

GX_WIDGET *gx_studio_widget_create(GX_BYTE *control, GX_CONST GX_STUDIO_WIDGET *definition, GX_WIDGET *parent)
{
    GX_WIDGET *widget;
    widget = gx_studio_nested_widget_create(control, definition, GX_NULL);

    if (parent && widget)
    {
        gx_widget_attach(parent, widget);
    }
    return widget;
}

UINT gx_studio_named_widget_create(char *name, GX_WIDGET *parent, GX_WIDGET **new_widget)
{
    UINT status = GX_FAILURE;
    GX_CONST GX_STUDIO_WIDGET_ENTRY *entry = endurer_widget_table;
    GX_WIDGET *widget = GX_NULL;

    while(entry->widget_information)
    {
        if (!strcmp(name, entry->widget_information->widget_name))
        {
            widget = gx_studio_widget_create((GX_BYTE *) entry->widget, entry->widget_information, parent);
            if (widget)
            {
                status = GX_SUCCESS;
            }
            break;
        }
        entry++;
    }

    if (new_widget)
    {
        *new_widget = widget;
    }
    return status;
}


UINT gx_studio_display_configure(USHORT display, UINT (*driver)(GX_DISPLAY *),
    GX_UBYTE language, USHORT theme, GX_WINDOW_ROOT **return_root)
{
    GX_CONST GX_THEME *theme_ptr;
    GX_RECTANGLE size;

    GX_STUDIO_DISPLAY_INFO *display_info = &endurer_display_table[display];


/* create the requested display                                                */

    gx_display_create(display_info->display,
                      display_info->name,
                      driver,
                      (GX_VALUE) display_info->x_resolution,
                      (GX_VALUE) display_info->y_resolution);


/* install the request theme                                                   */

    if(display_info->theme_table)
    {
        theme_ptr = display_info->theme_table[theme];
        if(theme_ptr)
        {
            gx_display_color_table_set(display_info->display, theme_ptr->theme_color_table, theme_ptr->theme_color_table_size);
            
/* install the color palette if required                                       */
            if (display_info->display->gx_display_driver_palette_set &&
                theme_ptr->theme_palette != NULL)
            {
                display_info->display->gx_display_driver_palette_set(display_info->display, theme_ptr->theme_palette, theme_ptr->theme_palette_size);
            }

            gx_display_font_table_set(display_info->display, theme_ptr->theme_font_table, theme_ptr->theme_font_table_size);
            gx_display_pixelmap_table_set(display_info->display, theme_ptr->theme_pixelmap_table, theme_ptr->theme_pixelmap_table_size);
            gx_system_scroll_appearance_set(theme_ptr->theme_vertical_scroll_style, (GX_SCROLLBAR_APPEARANCE *) &theme_ptr->theme_vertical_scrollbar_appearance);
            gx_system_scroll_appearance_set(theme_ptr->theme_horizontal_scroll_style, (GX_SCROLLBAR_APPEARANCE *) &theme_ptr->theme_horizontal_scrollbar_appearance);
            gx_display_language_table_set_ext(display_info->display, display_info->language_table, (GX_UBYTE) display_info->language_table_size, display_info->string_table_size);
            gx_display_active_language_set(display_info->display, language);
        }
    }


/* create the canvas for this display                                          */

    gx_canvas_create(display_info->canvas,
                     display_info->canvas_name,
                     display_info->display,
                     GX_CANVAS_MANAGED | GX_CANVAS_VISIBLE,
                     display_info->x_resolution,
                     display_info->y_resolution,
                     display_info->canvas_memory,
                     display_info->canvas_memory_size);

/* Create the root window for this canvas                                      */

    gx_utility_rectangle_define(&size,
                                0, 0,
                                (GX_VALUE) (display_info->x_resolution - 1),
                                (GX_VALUE) (display_info->y_resolution - 1));

    gx_window_root_create(display_info->root_window,
                          display_info->name,
                          display_info->canvas, GX_STYLE_NONE, 0, &size);
    if (return_root)
    {
        *return_root = display_info->root_window;
    }
    return GX_SUCCESS;
}

/* Provide display driver setup function                                       */

#if defined(GX_TARGET_WIN32) || defined(GX_TARGET_LINUX)

UINT _gx_synergy_display_driver_setup(GX_DISPLAY *display)
{
    win32_synergy_graphics_driver_setup_565rgb(display);
    return GX_SUCCESS;
}
#else
UINT _gx_synergy_display_driver_setup(GX_DISPLAY *display)
{
    _gx_display_driver_565rgb_setup(display, GX_NULL, _gx_dave2d_buffer_toggle);
    display->gx_display_handle =    0;
    display -> gx_display_driver_horizontal_pattern_line_draw  = _gx_dave2d_horizontal_pattern_line_draw_565;
    display -> gx_display_driver_vertical_pattern_line_draw    = _gx_dave2d_vertical_pattern_line_draw_565;
    display -> gx_display_driver_pixel_write                   = _gx_dave2d_pixel_write_565;
    display -> gx_display_driver_pixel_blend                   = _gx_dave2d_pixel_blend_565;
    display -> gx_display_driver_pixelmap_rotate               = _gx_dave2d_pixelmap_rotate_16bpp;
    display -> gx_display_driver_drawing_initiate              = _gx_dave2d_drawing_initiate;
    display -> gx_display_driver_drawing_complete              = _gx_dave2d_drawing_complete;
    display -> gx_display_driver_canvas_copy                   = _gx_dave2d_canvas_copy;
    display -> gx_display_driver_canvas_blend                  = _gx_dave2d_canvas_blend;
    display -> gx_display_driver_simple_line_draw              = _gx_dave2d_simple_line_draw;
    display -> gx_display_driver_horizontal_line_draw          = _gx_dave2d_horizontal_line;
    display -> gx_display_driver_vertical_line_draw            = _gx_dave2d_vertical_line;
    display -> gx_display_driver_polygon_draw                  = _gx_dave2d_polygon_draw;
    display -> gx_display_driver_polygon_fill                  = _gx_dave2d_polygon_fill;
    display -> gx_display_driver_block_move                    = _gx_dave2d_block_move;
    display -> gx_display_driver_pixelmap_draw                 = _gx_dave2d_pixelmap_draw;
    display -> gx_display_driver_horizontal_pixelmap_line_draw = _gx_dave2d_horizontal_pixelmap_line_draw;
    display -> gx_display_driver_alphamap_draw                 = _gx_dave2d_alphamap_draw;
    display -> gx_display_driver_simple_wide_line_draw         = _gx_dave2d_simple_wide_line;
    display -> gx_display_driver_anti_aliased_line_draw        = _gx_dave2d_aliased_line;
    display -> gx_display_driver_anti_aliased_wide_line_draw   = _gx_dave2d_aliased_wide_line;
    display -> gx_display_driver_pixelmap_blend                = _gx_dave2d_pixelmap_blend;
    display -> gx_display_driver_8bit_glyph_draw               = _gx_dave2d_raw_glyph_8bit_draw;
    display -> gx_display_driver_4bit_glyph_draw               = _gx_dave2d_raw_glyph_4bit_draw;
    display -> gx_display_driver_1bit_glyph_draw               = _gx_dave2d_raw_glyph_1bit_draw;
    display -> gx_display_driver_8bit_compressed_glyph_draw    = _gx_dave2d_compressed_glyph_8bit_draw;
    display -> gx_display_driver_4bit_compressed_glyph_draw    = _gx_dave2d_compressed_glyph_4bit_draw;
    display -> gx_display_driver_1bit_compressed_glyph_draw    = _gx_dave2d_compressed_glyph_1bit_draw;
    #if defined(GX_ARC_DRAWING_SUPPORT)
    display -> gx_display_driver_anti_aliased_circle_draw      = _gx_dave2d_aliased_circle_draw;
    display -> gx_display_driver_anti_aliased_wide_circle_draw = _gx_dave2d_aliased_circle_draw;
    display -> gx_display_driver_circle_draw                   = _gx_dave2d_circle_draw;
    display -> gx_display_driver_circle_fill                   = _gx_dave2d_circle_fill;
    display -> gx_display_driver_pie_fill                      = _gx_dave2d_pie_fill;
    display -> gx_display_driver_anti_aliased_arc_draw         = _gx_dave2d_aliased_arc_draw;
    display -> gx_display_driver_arc_draw                      = _gx_dave2d_arc_draw;
    display -> gx_display_driver_arc_fill                      = _gx_dave2d_arc_fill;
    display -> gx_display_driver_anti_aliased_ellipse_draw     = _gx_dave2d_aliased_ellipse_draw;
    display -> gx_display_driver_ellipse_draw                  = _gx_dave2d_ellipse_draw;
    display -> gx_display_driver_ellipse_fill                  = _gx_dave2d_ellipse_fill;
    display -> gx_display_driver_wide_circle_draw              = _gx_dave2d_circle_draw;
    display -> gx_display_driver_anti_aliased_wide_arc_draw    = _gx_dave2d_aliased_arc_draw;
    display -> gx_display_driver_wide_arc_draw                 = _gx_dave2d_arc_draw;
    display -> gx_display_driver_anti_aliased_wide_ellipse_draw= _gx_dave2d_aliased_ellipse_draw;
    display -> gx_display_driver_wide_ellipse_draw             = _gx_dave2d_ellipse_draw;
    #endif
    display -> gx_display_driver_jpeg_draw                     = _gx_synergy_jpeg_draw;
    return GX_SUCCESS;
}
#endif
#undef GUIX_STUDIO_GENERATED_FILE
