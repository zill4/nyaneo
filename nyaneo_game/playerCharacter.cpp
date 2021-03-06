#include "playerCharacter.h"

PlayerCharacter::PlayerCharacter()
{
	loadMedia();
}

PlayerCharacter::~PlayerCharacter()
{

}
bool PlayerCharacter::init_playercharacter(void)
{

}
void PlayerCharacter::update_playercharacter(Apple*, Graphics*)
{

}
void PlayerCharacter::change_direction(int)
{

}
void PlayerCharacter::check_collision(Apple*)
{

}
void PlayerCharacter::sprite_renderer(SDL_Rect*, Graphics*)
{

}
bool PlayerCharacter::loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load sprite sheet texture
	if (!spriteSheetTexture.loadFromFile("Assets/Knight/valiant_knight/style_B/spritesheet/spritesheet.png"))
	{
		printf("Failed to load walking animation texture!\n");
		success = false;
	}
	else
	{
		/* TODO: Need to create serializer for uploading spritesheets*/
		//  attack_A / frame0000 = 0 0 79 63
		//	attack_A / frame0001 = 79 0 79 63
		//	attack_A / frame0002 = 158 0 79 63
		//	attack_A / frame0003 = 237 0 79 63
		//	attack_A / frame0004 = 316 0 79 63
		//	attack_A / frame0005 = 395 0 79 63
		//	attack_A / frame0006 = 474 0 79 63
		//	attack_A / frame0007 = 553 0 79 63
		//	attack_A / frame0008 = 632 0 79 63
		//	attack_A / frame0009 = 711 0 79 63
		//	attack_A / frame0010 = 790 0 79 63
		//	attack_A / frame0011 = 869 0 79 63
		//	attack_A / frame0012 = 948 0 79 63
		//	attack_A / frame0013 = 1027 0 79 63
		//	attack_B / frame0000 = 0 63 79 63
		//	attack_B / frame0001 = 79 63 79 63
		//	attack_B / frame0002 = 158 63 79 63
		//	attack_B / frame0003 = 237 63 79 63
		//	attack_B / frame0004 = 316 63 79 63
		//	attack_B / frame0005 = 395 63 79 63
		//	attack_B / frame0006 = 474 63 79 63
		//	attack_B / frame0007 = 553 63 79 63
		//	attack_B / frame0008 = 632 63 79 63
		//	attack_B / frame0009 = 711 63 79 63
		//	attack_B / frame0010 = 790 63 79 63
		//	attack_B / frame0011 = 869 63 79 63
		//	attack_B / frame0012 = 948 63 79 63
		//	attack_C / frame0000 = 0 126 79 63
		//	attack_C / frame0001 = 79 126 79 63
		//	attack_C / frame0002 = 158 126 79 63
		//	attack_C / frame0003 = 237 126 79 63
		//	attack_C / frame0004 = 316 126 79 63
		//	attack_C / frame0005 = 395 126 79 63
		//	attack_C / frame0006 = 474 126 79 63
		//	attack_C / frame0007 = 553 126 79 63
		//	attack_C / frame0008 = 632 126 79 63
		//	attack_C / frame0009 = 711 126 79 63
		//	attack_C / frame0010 = 790 126 79 63
		//	attack_C / frame0011 = 869 126 79 63
		//	attack_C / frame0012 = 948 126 79 63
		//	attack_C / frame0013 = 1027 126 79 63
		//	die / frame0000 = 0 189 79 63
		//	die / frame0001 = 79 189 79 63
		//	die / frame0002 = 158 189 79 63
		//	die / frame0003 = 237 189 79 63
		//	die / frame0004 = 316 189 79 63
		//	die / frame0005 = 395 189 79 63
		//	die / frame0006 = 474 189 79 63
		//	die / frame0007 = 553 189 79 63
		//	die / frame0008 = 632 189 79 63
		//	die / frame0009 = 711 189 79 63
		//	fall_loop / frame0000 = 0 252 79 63
		//	fall_loop / frame0001 = 79 252 79 63
		//	get_hit / frame0000 = 0 315 79 63
		//	get_hit / frame0001 = 79 315 79 63
		//	get_hit / frame0002 = 158 315 79 63
		//	get_hit / frame0003 = 237 315 79 63
		//	get_hit / frame0004 = 316 315 79 63
		//	guard / frame0000 = 0 378 79 63
		//	guard / frame0001 = 79 378 79 63
		//	guard / frame0002 = 158 378 79 63
		//	guard / frame0003 = 237 378 79 63
		//	guard / frame0004 = 316 378 79 63
		//	guard / frame0005 = 395 378 79 63
		//	guard_end / frame0000 = 0 441 79 63
		//	guard_end / frame0001 = 79 441 79 63
		//	guard_end / frame0002 = 158 441 79 63
		//	guard_end / frame0003 = 237 441 79 63
		//	guard_start / frame0000 = 0 504 79 63
		//	guard_start / frame0001 = 79 504 79 63
		//	guard_start / frame0002 = 158 504 79 63
		//	guard_start / frame0003 = 237 504 79 63
		//	idle / frame0000 = 0 567 79 63
		//	idle / frame0001 = 79 567 79 63
		//	idle / frame0002 = 158 567 79 63
		//	idle / frame0003 = 237 567 79 63
		//	idle / frame0004 = 316 567 79 63
		//	idle / frame0005 = 395 567 79 63
		//	jump_start / frame0000 = 0 630 79 63
		//	jump_start / frame0001 = 79 630 79 63
		//	jump_start / frame0002 = 158 630 79 63
		//	jump_start / frame0003 = 237 630 79 63
		//	jump_loop / frame0000 = 316 630 79 63
		//	jump_loop / frame0001 = 395 630 79 63

		//	run / frame0000 = 0 693 79 63
		//	run / frame0001 = 79 693 79 63
		//	run / frame0002 = 158 693 79 63
		//	run / frame0003 = 237 693 79 63
		//	run / frame0004 = 316 693 79 63
		//	run / frame0005 = 395 693 79 63
		//	run / frame0006 = 474 693 79 63
		//	run / frame0007 = 553 693 79 63
		//Set sprite clips
		spriteClips[0].x = 0;
		spriteClips[0].y = 693;
		spriteClips[0].w = 79;
		spriteClips[0].h = 63;

		spriteClips[1].x = 79;
		spriteClips[1].y = 693;
		spriteClips[1].w = 79;
		spriteClips[1].h = 63;

		spriteClips[2].x = 158;
		spriteClips[2].y = 693;
		spriteClips[2].w = 79;
		spriteClips[2].h = 63;

		spriteClips[3].x = 237;
		spriteClips[3].y = 693;
		spriteClips[3].w = 79;
		spriteClips[3].h = 63;
	}

	return success;
}