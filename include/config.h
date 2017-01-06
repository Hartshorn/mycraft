#pragma once

#define WORKERS_COUNT		4
#define MAX_CHUNKS			8192
#define MAX_TEXT_LENGTH		256
#define MAX_NAME_LENGTH		32
#define MAX_PLAYERS			128
#define MAX_MESSAGES		4
#define MAX_PATH_LENGTH		256
#define MAX_SIGN_LENGTH		64

#define WINDOW_WIDTH		1024
#define WINDOW_HEIGHT		768

#define FULLSCREEN			0
#define VSYNC				1
#define MODE_OFFLINE		0
#define MODE_ONLINE			1
#define DB_PATH				"mycraft.db"

#define CREATE_CHUNK_RADIUS 10
#define RENDER_CHUNK_RADIUS 10
#define RENDER_SIGN_RADIUS  4
#define DELETE_CHUNK_RADIUS 14
#define CHUNK_SIZE          32
#define COMMIT_INTERVAL     5

#define WORKER_IDLE         0 
#define WORKER_BUSY         1
#define WORKER_DONE         2