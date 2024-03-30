/******************************************************************************
 *brief: Display driver hardware interface header file
 *author: cF-embedded.pl
 ******************************************************************************/

#ifndef __DISPLAY_HARDWARE_H
#define __DISPLAY_HARDWARE_H

typedef struct
{
    void (*display_hardware_init)(void);
    void (*display_hardware_set_char)(char);
    void (*display_hardware_clear)(void);
    void (*display_hardware_set_header)(void);
} display_hardware_s_t;

void display_hardware_init(void);
void display_hardware_set_char(void);
void display_hardware_clear(void);
void display_hardware_set_header(void);

#endif /* __DISPLAY_HARDWARE_H */