#include<SDL.h>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>
#include<iostream>
using namespace std;


void applybirrd(SDL_Surface* surface, SDL_Surface* bird, SDL_Rect* rect)
{
	int temp1, temp2;
	temp1 = (*rect).x;
	temp2 = (*rect).y;
	SDL_BlitSurface(bird, NULL, surface, rect);
	(*rect).x = temp1;
	(*rect).y = temp2;
}

void flydown(SDL_Surface* surface, SDL_Surface* bird, SDL_Rect* rect)
{
	int temp1, temp2;
	(*rect).y = (*rect).y + 4;
	temp1 = (*rect).x;
	temp2 = (*rect).y;
	applybirrd(surface, bird, rect);
	(*rect).x = temp1;
	(*rect).y = temp2;
}

void flyup(SDL_Surface* surface, SDL_Surface* bird, SDL_Rect* rect)
{
	(*rect).y = (*rect).y - 5;
	int temp1, temp2;
	temp1 = (*rect).x;
	temp2 = (*rect).y;
	applybirrd(surface, bird, rect);
	(*rect).x = temp1;
	(*rect).y = temp2;
}

void bird_active(SDL_Surface* surface, SDL_Surface* bird, SDL_Rect* rect, SDL_Event e)
{
	if (e.type == SDL_KEYDOWN)
	{
		//Select surfaces based on key press
		flyup(surface, bird, rect);
		SDL_Delay(60);
	}
	else {
		flydown(surface, bird, rect);
		SDL_Delay(50);
	}
}

void applyIMG(SDL_Surface* surface, SDL_Surface* IMG, SDL_Rect* rect)
{
	int temp1, temp2;
	temp1 = (*rect).x;
	temp2 = (*rect).y;
	SDL_BlitSurface(IMG, NULL, surface, rect);
	(*rect).x = temp1;
	(*rect).y = temp2;
}

void runpipe(SDL_Surface* surface, SDL_Surface* pipe, SDL_Rect* rect)
{
		(*rect).x = (*rect).x - 5;
		int temp1, temp2;
		temp1 = (*rect).x;
		temp2 = (*rect).y;
		SDL_BlitSurface(pipe, NULL, surface, rect);
		(*rect).x = temp1;
		(*rect).y = temp2;
}

void born_pipe(SDL_Surface * pipe, SDL_Surface * font, SDL_Rect * rect, SDL_Surface * surface)
{
	srand(time(0));
	int temp1,temp2;
	SDL_Rect rect_in ;
	(*rect).y =(-2+ -(rand() %4 )) * 30;
	(*rect).x = 800;
	temp1 = (*rect).y;
	temp2 = (*rect).x;
	SDL_BlitSurface(font, NULL, surface, NULL);
	SDL_BlitSurface(pipe, NULL, surface, rect);
	(*rect).y = temp1;
}

void mannu(SDL_Event e,SDL_Surface* menu,SDL_Surface* surface,bool flag)
{
	flag = true;
	while (flag) {
		SDL_BlitSurface(menu, NULL, surface, NULL);
		if (e.type == SDL_KEYDOWN) {
			if (e.key.keysym.sym == SDLK_SPACE) {
				break;
			}
			else {
				flag = false;
				break;
			}
		}
	}
}


int main(int argc, char* argv[])
{
	SDL_Window* window = NULL;
	SDL_Surface* surface = NULL;
	SDL_Surface* bird = NULL;
	SDL_Surface* font = NULL;
	SDL_Surface* pipe = NULL;
	SDL_Surface* pipe_in = NULL;
	SDL_Surface* CRASH = NULL;
	SDL_Surface* menu = NULL;
	SDL_Event e;
	SDL_Rect rect1;
	SDL_Rect rect2;
	SDL_Rect rect3;
	SDL_Rect rect4;
	SDL_Rect rect;
	rect.x = 30;
	rect.y = 0;

	SDL_Rect rect11;
	SDL_Rect rect21;
	SDL_Rect rect31;
	SDL_Rect rect41;

	menu = SDL_LoadBMP("menu.bmp");
	pipe_in = SDL_LoadBMP("pipe_in.bmp");
	window = SDL_CreateWindow("flydown", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 500, SDL_WINDOW_SHOWN);
	surface = SDL_GetWindowSurface(window);
	bird = SDL_LoadBMP("Bird.bmp");
	CRASH = SDL_LoadBMP("CRASH.bmp");
	font = SDL_LoadBMP("font.bmp");
	pipe = SDL_LoadBMP("pipe_on.bmp");

	int t = 0;
	

	born_pipe(pipe, font, &rect1, surface);
	rect11.y = rect1.y + 400;
	rect11.x = rect1.x;
	SDL_Delay(1000);

	born_pipe(pipe, font, &rect2, surface);
	rect21.y = rect2.y + 400;
	rect21.x = rect2.x;
	SDL_Delay(1000);

	born_pipe(pipe, font, &rect3, surface);
	rect31.y = rect3.y + 400;
	rect31.x = rect3.x;
	SDL_Delay(1000);

	born_pipe(pipe, font, &rect4, surface);
	rect41.y = rect4.y + 400;
	rect41.x = rect4.x;

	bool flag = true;
	while (flag) {
		SDL_UpdateWindowSurface(window);
		SDL_BlitSurface(font, NULL, surface, NULL);

		if (rect1.x > 600) {
			runpipe(surface, pipe, &rect1);
			runpipe(surface, pipe_in, &rect11);
		}
		else {
			if (rect1.x > 400) {
				runpipe(surface, pipe, &rect1);
				runpipe(surface, pipe, &rect2);
				runpipe(surface, pipe_in, &rect11);
				runpipe(surface, pipe_in, &rect21);

			}
			else if (rect1.x > 200) {
				runpipe(surface, pipe, &rect1);
				runpipe(surface, pipe, &rect2);
				runpipe(surface, pipe, &rect3);
				runpipe(surface, pipe_in, &rect11);
				runpipe(surface, pipe_in, &rect21);
				runpipe(surface, pipe_in, &rect31);

			}
			else {
				if (rect1.x > -20) {
					runpipe(surface, pipe, &rect1);
					runpipe(surface, pipe, &rect2);
					runpipe(surface, pipe, &rect3);
					runpipe(surface, pipe, &rect4);
					runpipe(surface, pipe_in, &rect11);
					runpipe(surface, pipe_in, &rect21);
					runpipe(surface, pipe_in, &rect31);
					runpipe(surface, pipe_in, &rect41);

				}
				else {
					runpipe(surface, pipe, &rect1);
					runpipe(surface, pipe, &rect2);
					runpipe(surface, pipe, &rect3);
					runpipe(surface, pipe, &rect4);
					runpipe(surface, pipe_in, &rect11);
					runpipe(surface, pipe_in, &rect21);
					runpipe(surface, pipe_in, &rect31);
					runpipe(surface, pipe_in, &rect41);
				}
			}
		}
		SDL_PollEvent(&e);
		bird_active(surface, bird,  &rect, e);
		if (rect1.x == 0) {
			//born_pipe(pipe, font, &rect1, surface);

			srand(time(0));
			int temp3, temp4;
			SDL_Rect rect_in;
			(rect1).y = (-2 + -(rand() % 4)) * 30;
			(rect1).x = 800;
			temp3 = (rect1).y;
			temp4 = (rect1).x;
			SDL_BlitSurface(pipe, NULL, surface,& rect1);
			(rect1).y = temp3;

			srand(time(0));
			(rect11).y = (-2 + -(rand() % 4)) * 30;
			(rect11).x = 800;
			temp3 = (rect11).y;
			temp4 = (rect11).x;
			SDL_BlitSurface(pipe_in, NULL, surface, &rect11);
			(rect11).y = temp3;


			int temp1,temp2;
			temp1 = rect1.x;
			temp2 = rect2.y;
			rect1.x = rect2.x;
			rect1.y = rect2.y;
			rect2.x = rect3.x;
			rect2.y = rect3.y;
			rect3.x = rect4.x;
			rect3.y = rect4.y;
			rect4.x = temp1;
			rect4.y = temp2;

			temp1 = rect11.x;
			temp2 = rect21.y;
			rect11.x = rect21.x;
			rect11.y = rect21.y;
			rect21.x = rect31.x;
			rect21.y = rect31.y;
			rect31.x = rect41.x;
			rect31.y = rect41.y;
			rect41.x = temp1;
			rect41.y = temp2;

			cout << rect4.x << ' ' << rect1.x << endl;
		}
		if ((rect.y >= rect1.y && rect.y <= rect1.y + 320 && rect.x + 60 == rect1.x) || (rect.y + 48 >= rect11.y && rect.y + 48 <= rect11.y + 320 && rect.x + 60 == rect11.x)) {
			mannu(e, menu, surface, flag);
		}
	}

	return 0;
}
