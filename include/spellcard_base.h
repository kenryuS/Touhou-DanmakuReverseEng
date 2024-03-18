#ifndef SPELLCARD_BASE_H_
#define SPELLCARD_BASE_H_

typedef enum {
    CARD_NORMAL = 1,
    CARD_ENDUR
} cardType;

typedef struct {
    char* name;
    unsigned int duration;
    cardType type;
} spellcard;

#endif // SPELLCARD_BASE_H_
