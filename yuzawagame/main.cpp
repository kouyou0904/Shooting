#include "DxLib.h"
#include <ctime>
#include <cstdlib>
#include <math.h>

const int WIDTH = 640;
const int HEIGHT = 480;
const int WHITE = GetColor( 255, 255, 255 );
const int RED = GetColor( 255, 0, 0 );
const int BLUE = GetColor( 0, 0, 255 );
int x = WIDTH / 2;
int y = HEIGHT - 20;
int ground_cnt = 0;
int tama_x = x;
int tama_y = y;
int o = 0;
int cnt = 0;

bool tama = false;
bool teki = false;

typedef struct 
{
	int teki_x;
	int teki_y;
} enemy;
enemy a[10] ={ { 0, 0 } };

int key[ 256 ] = { 0 };

int inputKeyState( ) {
	char key_c[ 256 ];
	GetHitKeyStateAll( key_c );

	for ( int i = 0; i < 256; i++ ) {
		if ( key_c[ i ] ) {
			key[ i ]++;
		} else {
			key[ i ] = 0;
		}
	}

	return 0;
}



int WINAPI WinMain( HINSTANCE hinstance, HINSTANCE hPrevlnstance, LPSTR lpCmdLine, int nCmdShow ) {
	ChangeWindowMode( 1 );
	if ( DxLib_Init( ) != 0 ) {
		return -1;
	}

	SetDrawScreen( DX_SCREEN_BACK );

	srand( time( NULL ) );
	//int teki_y = rand( ) % 320;
	//int teki_x = rand( ) % 240;

	
	while ( 1 ){
		ClearDrawScreen( );
		ProcessMessage( );
		inputKeyState( );
		
		enemy { rand( ) % 640, rand( ) % 2 };

		if ( x <= 0 + 10 ){
			x = 0 + 10;
		}

		if ( x >= WIDTH - 10 ){
			x = WIDTH - 10;
		}

		if ( y <= 0 ){
			y = 0;
		}

		if ( y >= HEIGHT -10 ){
			y = HEIGHT -10;
		}

		if ( key[ KEY_INPUT_ESCAPE ] == 1 ) {
			break;
		}

		if ( key[ KEY_INPUT_UP ] ) {
			y -= 5;
		}
		if ( key[ KEY_INPUT_DOWN ] ) {
			y += 5;
		}
		if ( key[ KEY_INPUT_RIGHT ] ) {
			x += 5;
		}
		if ( key[ KEY_INPUT_LEFT ]  ) {
			x -= 5;
		}
		
		/*for ( int i = 0; i < 15; i++ ){

		}*/

		if ( ground_cnt % 150 == 0 && tama == false ) {
			tama = true;
			tama_x = x;
			tama_y = y;
		}

		if ( tama ){
			tama_y -= 10;
			if ( tama_y < 0 ) {
				tama = false;
			}
		}

		if ( tama ) {
			DrawCircle(tama_x, tama_y, 5, WHITE, TRUE);
		}

		
			if( ( ground_cnt + 1 ) % 100 == 0){

				a[o].teki_x = rand( ) % 640;
				a[o].teki_y = 0;
				o++;
				cnt++;
				if( cnt > 10 ){
					cnt = 10;
				}
				
			}
			for( int i = 0; i < cnt; i++ ){
				DrawCircle( a[i].teki_x, a[i].teki_y, 10, BLUE, TRUE );
				a[i].teki_y += 3;
			}

			if( o > 10 ){
				o = 0;
			}

		/*if ( ( ground_cnt + 1 ) % 100 == 0 && teki == false ){
			teki = true;
			a[i].teki_x = rand( ) % 640;
			a[i].teki_y = ;
		}

		if ( teki ){
			a[i].teki_y += 3;
			if ( a[i].teki_y > 480 ){
				teki = false;

			}
		}

		if ( teki ){
			DrawCircle( a[i].teki_x, a[i].teki_y, 10, BLUE, TRUE );
		}*/

		DrawCircle( x, y, 10, RED, TRUE );
		//DrawCircle(100, 100, 5, WHITE, TRUE);
		DrawFormatString( 0, 0, RED, "%d", ground_cnt );
		//DrawFormatString(x, y, RED, "%d,%d", x, y);
		//DrawCircle( lucky, lucky, 10, BLUE, TRUE );
		ground_cnt++;

		ScreenFlip();
	}
	
	

	DxLib_End();
	return 0;
}