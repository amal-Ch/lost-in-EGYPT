//#ifndef JEU_H_
//#define JEU_H_
void input(int *k,int *continuer);
void deplacement(int k,SDL_Rect *positionperso);
void animation_perso(int k,int *iRight,int *iLeft,int *iUp,int *iDown);
void update(int k,int *iRight,int *iLeft,int *iUp,int *iDown,SDL_Rect *positionperso);
void game(SDL_Surface *ecran,int *continuer);
void pause();


//#endif
