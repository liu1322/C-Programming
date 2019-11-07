#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

void print_card(card_t c);
void assert_card_valid(card_t c);

void print_hand(deck_t * hand){
  size_t n = hand -> n_cards;
  card_t ** ptr = hand -> cards;
  for (int i=0; i < n; i++){
    print_card(*ptr[i]);
  }
}

int deck_contains(deck_t * d, card_t c) {
  size_t n = d -> n_cards;
  card_t ** ptr = d -> cards;
  for (int i=0; i < n; i++){
    if(value_letter(*ptr[i]) == value_letter(c) && suit_letter(c)==suit_letter(*ptr[i])){
      return 1;
    }
  }
  return 0;
}

void shuffle(deck_t * d){
  size_t n = d -> n_cards;
  card_t ** ptr = d -> cards;

  for (int i = 0; i < n; i++)
    {
      int r = rand()% (n - 1);
      card_t temp = *ptr[r];
      *ptr[r] = *ptr[i];
      *ptr[i] = temp;
    } 
}

void assert_full_deck(deck_t * d) {
  size_t n = d -> n_cards;
  card_t ** ptr = d -> cards;

  for (int i=0; i < n; i++){
    assert_card_valid(*ptr[i]);
    int res = deck_contains(d, *ptr[i]);
    assert(res == 1);
  }
}
