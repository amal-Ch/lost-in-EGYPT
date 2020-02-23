#include <stdlib.h>

#include <stdio.h>

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include <SDL/SDL_image.h>

#include <SDL/SDL_mixer.h>

void pause() {
  int continuer = 1;
  SDL_Event event;
  while (continuer) {
    SDL_WaitEvent( & event);
    switch (event.type) {
    case SDL_QUIT:
      continuer = 0;
    }
  }
}
void jouer(SDL_Surface* ecran){
 SDL_Surface *imageDeFond = NULL;
SDL_Rect positionFond;
imageDeFond=SDL_LoadBMP("2.bmp");
SDL_BlitSurface(imageDeFond, NULL, ecran, & positionFond);}


void setting(SDL_Surface* ecran){
 SDL_Surface *option = NULL;
SDL_Rect positionoption;
option=SDL_LoadBMP("options.bmp");
SDL_BlitSurface(option, NULL, ecran, & positionoption);}

int main(int argc, char * argv[]) {
    SDL_Surface * ecran = NULL,* option =NULL, * imageDeFond = NULL, *imageDeFond1= NULL, * affiche = NULL, * affiche1 = NULL, * affiche2 = NULL,*text = NULL,*back = NULL;
    SDL_Rect positionFond, positionAffiche, positionAffiche1, positionAffiche2,positionFond1, posText, posBack;
    //SDL_Color whitecolor = {255, 255, 255};
  // TTF_Font* font = NULL;

    SDL_Event event;
    int continuer = 1;
    positionFond.x = 0;
    positionFond.y = 0;
    positionAffiche.x = 450;
    positionAffiche.y = 140;

    positionAffiche1.x = 450;
    positionAffiche1.y = 260;

    positionAffiche2.x = 450;
    positionAffiche2.y = 380;

        posText.x = 250;
	posText.y = 50;

	posBack.x = 0;
	posBack.y = 0;
	

	
	

    SDL_Init(SDL_INIT_VIDEO);

    TTF_Init();
    SDL_WM_SetIcon(SDL_LoadBMP("sdl_icone.bmp"), NULL);
    ecran = SDL_SetVideoMode(900, 510, 32, SDL_HWSURFACE | SDL_DOUBLEBUF /*| SDL_FULLSCREEN*/);


    SDL_WM_SetCaption("Lost in Egypt", NULL);
    imageDeFond = SDL_LoadBMP("bgplay.bmp");


    SDL_BlitSurface(imageDeFond, NULL, ecran, & positionFond);
    affiche = SDL_LoadBMP("paly1.bmp");
    SDL_BlitSurface(affiche, NULL, ecran, & positionAffiche);
    affiche1 = SDL_LoadBMP("option1.bmp");
    SDL_BlitSurface(affiche1, NULL, ecran, & positionAffiche1);
    affiche2 = SDL_LoadBMP("quit1.bmp");
    SDL_BlitSurface(affiche2, NULL, ecran, & positionAffiche2);
         
int test=0;




    //musique
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) {
      printf("%s", Mix_GetError());
    }
    Mix_Music * musique;
    musique = Mix_LoadMUS("song.mp3");
    Mix_Chunk * click;
    click = Mix_LoadWAV("ButtonClick.wav");
    Mix_PlayMusic(musique, -1);
    //endmusique

//creer une police
TTF_Font *font;
 font = TTF_OpenFont("font.ttf",40);
SDL_Color fontcolor={0,0,0};
//creer une zone texte
		
		text = TTF_RenderText_Blended(font, "Lost in EGYPT", fontcolor);

		SDL_BlitSurface(text, NULL, ecran, &posText);	
		SDL_Flip(ecran);



     while (continuer) {
     SDL_PollEvent( & event) 
        
        if(enevt.type==SDL_KEYDOWN) {
         
           if(event.key.keysym.sym==SDLK_ESCAPE){
            break;
            }
         else if(event.key.keysym.sym==SDLK_j){
           jouer(ecran);
            test=1;
           Mix_VolumeChunk(click,0);
         }
       }
         
                
     else if (enevt.type==SDL_MOUSEBUTTONUP){

if(event.button.x >= 450 && event.button.x <= 900 && event.button.y >=140 && event.button.y <= 280 )
{              
                
jouer(ecran);
test=1;
Mix_VolumeChunk(click,0);
 SDL_Flip(ecran);
               
}
else if(event.button.x >=450 && event.button.x <= 900 && event.button.y >=260 && event.button.y <= 380 )
{                  setting(ecran);
                   test=1;
                     Mix_VolumeChunk(click,0);
                 SDL_Surface *back;      
              back = IMG_Load("back.png");
                SDL_BlitSurface(back, NULL, ecran, & posBack);
             SDL_Flip(ecran); 


               
                  //Mix_PlayChannel(-1,click,0);
                 SDL_Flip(ecran);}
else if(event.button.x >= 450 && event.button.x <=900 && event.button.y >=410 && event.button.y <=510 )
{
exit(0);
        
}
}
 else if(enevt.type== SDL_MOUSEMOTION)
        {  if(test==0)
            {if (event.button.x >= 450 && event.button.x <= 900 && event.button.y >= 140 && event.button.y <= 280)
               {        
                affiche=SDL_LoadBMP("paly2.bmp");
             SDL_BlitSurface(affiche, NULL, ecran, & positionAffiche);
                Mix_PlayChannel(-1,click,0);
                }
                else{
                affiche=SDL_LoadBMP("paly1.bmp");
               SDL_BlitSurface(affiche, NULL, ecran, & positionAffiche);
            }
            }
             if (event.button.x >= 450 && event.button.x <= 900 && event.button.y >= 260 && event.button.y <=380) 
                 {
              affiche1=SDL_LoadBMP("option2.bmp");
       SDL_BlitSurface(affiche1, NULL, ecran, & positionAffiche1);
                    SDL_Flip(ecran);
                    Mix_PlayChannel(-1,click,0);

              option = SDL_LoadBMP("back.png");
                SDL_BlitSurface(option, NULL, ecran, & posBack);


               }
               else
                { affiche1=SDL_LoadBMP("option1.bmp");
                   SDL_BlitSurface(affiche1, NULL, ecran, & positionAffiche1);
                 SDL_Flip(ecran);

                     }  
            if (event.button.x >=450 && event.button.x <=900 && event.button.y >=410 && event.button.y <=510) 
                {
              affiche2=SDL_LoadBMP("quit2.bmp");
              SDL_BlitSurface(affiche2, NULL, ecran, & positionAffiche2);
                        SDL_Flip(ecran);
                   Mix_PlayChannel(-1,click,0);
                    }
                else{ affiche2=SDL_LoadBMP("quit1.bmp");
                 SDL_BlitSurface(affiche2, NULL, ecran, & positionAffiche2);
              SDL_Flip(ecran);
                
            }
            }
          

          }



}



      SDL_Flip(ecran);
      pause();
      Mix_FreeChunk(click);
      SDL_FreeSurface(imageDeFond);
      SDL_FreeSurface(affiche);
      SDL_FreeSurface(affiche1);
      SDL_FreeSurface(affiche2);
 SDL_FreeSurface(back);
      Mix_FreeMusic(musique);
      Mix_CloseAudio();
      TTF_CloseFont(font);/*closing the font before freeing the momory*/
      TTF_Quit();
      SDL_Quit();
return EXIT_SUCCESS;
}
