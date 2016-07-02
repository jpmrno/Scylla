#include <commands.h>
#include <stdio.h>
#include <console.h>
#include <songs.h>
#include <string.h>

void play_song(char * songDirections);

extern void sys_play_note(uint32_t frec, uint32_t length);

static uint32_t notes[26] = {11492, 10847, 9121, 8609, 8126, 7670, 7239, 6833, 6449, 6087, 5743, 5423, 5119, 4831, 4560, 4304, 4063, 3834, 3619, 3416, 3224, 3043, 2873, 2711, 2559, 2416};



char RICK[] = "K1M1P1M1T2T3R5K1M1P1M1R3R3P6K1M1P1M1P4R2O4M2K4R4P50";
char BECAUSE[] = "D1K1P1S1P1K1G1K1D1K1P1S1P1K1G1K1F1L1P1R1P1L1G1I1F1K1O1R1O1K1A1K1B1L1P1S1P1L1G1L1D1K1P1S1P1K1A1K1B1J1P1V1P1J1G1J1B1J1P1U4E1L1Q1U1Q1L1I1L1E1K1Q1U1T30";

COMMAND_FUNCTION(songs);
COMMAND_HELP(songs);

COMMAND_FUNCTION(songs) {
	if(argc == 0 || argc >= 2){
		printf("Please enter a valid song number\n$>");
		return ERROR;
		
	}
	
	if(strcmp(argv[0], "1") == 0){
		play_song(RICK);
	}else if(strcmp(argv[0], "2") == 0){
		play_song(BECAUSE);
	}
	return OK;
}

COMMAND_HELP(songs) {
	if(argc >= 1) {
		printf("<ps> Error: too many arguments.\n");
		return ERROR;
	}

	printf("Plays Song.\n");
	printf("Usage: 'songs'\n");

	return OK;
}

void play_song(char* songsDirections){
	int i=0, j=0;
	while(j<10){
		uint32_t tempo = 400;
		while(songsDirections[i] != '0'){
			uint32_t notePos = songsDirections[i] - 'A';
			uint32_t note = notes[notePos];
			uint8_t len = songsDirections[i+1] - '0';
			uint32_t aux = tempo * len;
			sys_play_note(note, aux);
			i+=2;
		} 
		j++;
	}
}