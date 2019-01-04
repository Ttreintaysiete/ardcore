#include "sample0.h"

prog_uchar sample0_data[sample0_size] = {
	134, 122, 175, 216, 53, 137, 172, 89, 180, 91, 102, 141, 160, 138, 86, 157, 
	101, 152, 125, 105, 200, 39, 177, 182, 2, 158, 191, 171, 97, 120, 173, 78, 
	101, 140, 58, 129, 231, 158, 38, 151, 216, 29, 86, 255, 71, 95, 161, 104, 
	142, 161, 122, 110, 142, 107, 117, 114, 160, 67, 141, 181, 83, 135, 162, 109, 
	37, 181, 222, 57, 141, 126, 115, 151, 170, 93, 125, 150, 78, 179, 108, 161, 
	114, 114, 158, 153, 139, 99, 146, 118, 160, 86, 146, 144, 132, 158, 114, 126, 
	125, 113, 124, 163, 98, 163, 120, 89, 139, 130, 150, 83, 194, 96, 163, 72, 
	149, 154, 106, 155, 90, 164, 113, 135, 144, 84, 173, 107, 111, 126, 145, 118, 
	128, 145, 136, 131, 117, 136, 133, 129, 120, 134, 111, 156, 128, 142, 102, 128, 
	115, 125, 139, 134, 163, 101, 135, 119, 156, 112, 120, 101, 167, 132, 129, 150, 
	87, 167, 101, 120, 155, 130, 105, 154, 130, 112, 148, 118, 118, 110, 172, 103, 
	149, 148, 99, 132, 113, 135, 121, 115, 138, 128, 140, 138, 88, 140, 159, 117, 
	105, 160, 130, 137, 102, 121, 176, 121, 128, 104, 148, 143, 114, 106, 166, 107, 
	164, 134, 84, 153, 136, 123, 162, 98, 129, 139, 135, 130, 119, 146, 137, 131, 
	90, 162, 118, 139, 113, 129, 134, 113, 151, 125, 111, 142, 142, 142, 112, 128, 
	145, 152, 107, 109, 135, 161, 118, 141, 98, 139, 131, 136, 118, 104, 167, 112, 
	130, 118, 83, 202, 127, 98, 154, 116, 143, 107, 128, 153, 164, 71, 128, 163, 
	113, 117, 141, 120, 128, 139, 147, 80, 150, 146, 107, 143, 84, 153, 152, 123, 
	138, 136, 112, 117, 154, 124, 143, 136, 89, 176, 114, 87, 168, 137, 104, 134, 
	155, 103, 148, 125, 89, 161, 129, 101, 159, 122, 126, 137, 125, 135, 130, 136, 
	126, 119, 132, 137, 117, 128, 149, 116, 129, 160, 82, 175, 149, 94, 136, 148, 
	105, 137, 132, 122, 130, 136, 118, 126, 165, 91, 147, 134, 137, 131, 82, 172, 
	116, 147, 101, 162, 114, 134, 123, 128, 162, 106, 123, 129, 129, 166, 93, 109, 
	175, 92, 132, 152, 122, 129, 133, 135, 97, 155, 118, 139, 163, 62, 150, 134, 
	127, 139, 129, 128, 134, 98, 137, 167, 110, 139, 111, 123, 150, 132, 149, 95, 
	140, 128, 132, 124, 124, 162, 113, 121, 140, 132, 117, 136, 148, 114, 97, 168, 
	130, 138, 122, 132, 109, 137, 151, 80, 175, 112, 121, 148, 113, 155, 128, 117, 
	128, 130, 139, 109, 151, 128, 153, 94, 127, 149, 114, 157, 103, 152, 96, 132, 
	167, 93, 148, 119, 122, 158, 109, 128, 124, 172, 101, 126, 136, 110, 159, 134, 
	113, 100, 178, 126, 90, 178, 120, 109, 140, 114, 156, 136, 130, 122, 128, 147, 
	113, 138, 128, 143, 117, 130, 129, 119, 149, 110, 141, 128, 113, 136, 153, 126, 
	112, 131, 138, 120, 138, 138, 125, 122, 127, 124, 150, 126, 140, 108, 133, 129, 
	117, 143, 137, 114, 116, 167, 104, 123, 148, 121, 121, 131, 148, 117, 130, 117, 
	132, 162, 106, 108, 149, 131, 124, 125, 124, 129, 138, 131, 134, 133, 100, 140, 
	131, 148, 155, 94, 143, 134, 125, 133, 134, 120, 137, 109, 127, 153, 122, 113, 
	171, 80, 154, 126, 103, 143, 152, 115, 137, 115, 151, 117, 123, 138, 126, 151, 
	113, 124, 145, 139, 118, 127, 115, 150, 123, 139, 118, 135, 127, 133, 128, 132, 
	128, 135, 131, 109, 154, 116, 140, 125, 147, 83, 147, 120, 152, 108, 111, 141, 
	142, 128, 126, 123, 136, 134, 132, 110, 160, 132, 133, 116, 128, 137, 131, 146, 
	109, 141, 129, 118, 114, 147, 148, 125, 116, 133, 112, 145, 141, 140, 117, 94, 
	157, 120, 141, 109, 146, 132, 115, 138, 133, 128, 129, 132, 125, 125, 127, 136, 
	130, 127, 134, 120, 136, 133, 106, 161, 117, 130, 128, 118, 145, 121, 133, 120, 
	127, 135, 136, 118, 140, 122, 141, 112, 141, 131, 135, 115, 131, 132, 145, 120, 
	126, 148, 106, 137, 133, 131, 129, 133, 120, 128, 131, 140, 123, 138, 127, 113, 
	128, 137, 141, 121, 126, 128, 117, 156, 125, 105, 158, 123, 132, 109, 156, 112, 
	139, 143, 104, 146, 118, 123, 135, 129, 126, 133, 122, 133, 123, 153, 116, 135, 
	122, 130, 139, 133, 129, 117, 129, 133, 149, 110, 132, 132, 127, 132, 116, 136, 
	128, 142, 115, 138, 132, 99, 154, 142, 113, 128, 145, 118, 128, 133, 138, 110, 
	141, 137, 113, 149, 116, 135, 117, 136, 136, 130, 124, 136, 133, 125, 134, 129, 
	140, 122, 124, 130, 132, 135, 116, 129, 146, 109, 143, 110, 124, 143, 132, 128, 
	113, 142, 129, 128, 144, 118, 133, 116, 141, 126, 136, 143, 107, 134, 137, 125, 
	131, 128, 126, 130, 133, 115, 131, 150, 103, 143, 116, 144, 133, 107, 144, 140, 
	126, 116, 126, 138, 135, 132, 116, 146, 120, 121, 128, 138, 138, 123, 125, 130, 
	136, 128, 128, 128, 146, 114, 126, 147, 133, 113, 138, 129, 125, 145, 119, 125, 
	141, 115, 146, 124, 128, 131, 124, 138, 121, 132, 127, 127, 131, 139, 121, 126, 
	139, 121, 139, 122, 128, 137, 110, 143, 144, 120, 115, 140, 129, 137, 125, 132, 
	122, 132, 136, 128, 134, 127, 130, 104, 165, 117, 127, 133, 119, 144, 120, 123, 
	131, 142, 128, 121, 132, 132, 129, 127, 130, 130, 132, 116, 130, 147, 111, 141, 
	136, 111, 143, 131, 124, 130, 128, 136, 120, 125, 143, 129, 120, 142, 118, 129, 
	134, 133, 130, 125, 130, 128, 133, 127, 122, 139, 129, 124, 133, 133, 113, 154, 
	125, 127, 127, 117, 146, 128, 130, 132, 119, 133, 132, 122, 137, 123, 134, 128, 
	128, 131, 138, 122, 116, 135, 136, 129, 128, 122, 139, 127, 130, 121, 138, 129, 
	126, 138, 107, 145, 130, 128, 127, 132, 135, 120, 136, 127, 131, 134, 123, 145, 
	119, 120, 146, 125, 128, 130, 132, 129, 125, 138, 126, 130, 125, 137, 128, 124, 
	144, 116, 132, 126, 140, 126, 125, 138, 122, 131, 131, 121, 136, 125, 127, 137, 
	124, 131, 138, 126, 128, 130, 128, 131, 139, 119, 121, 145, 124, 127, 150, 113, 
	128, 135, 120, 141, 123, 134, 130, 128, 131, 127, 130, 128, 126, 141, 126, 116, 
	142, 129, 129, 122, 138, 127, 127, 133, 124, 128, 135, 133, 130, 125, 128, 126, 
	137, 135, 124, 121, 140, 128, 133, 126, 131, 124, 136, 123, 135, 125, 132, 129, 
	125, 139, 124, 128, 127, 131, 133, 129, 124, 135, 133, 123, 130, 125, 134, 135, 
	122, 137, 127, 136, 128, 123, 133, 122, 141, 126, 131, 129, 136, 124, 128, 127, 
	134, 130, 130, 126, 133, 127, 137, 128, 128, 134, 128, 132, 119, 131, 129, 137, 
	125, 131, 138, 115, 133, 133, 122, 143, 128, 123, 133, 128, 128, 125, 136, 122, 
	136, 129, 128, 132, 126, 127, 135, 130, 128, 126, 128, 134, 125, 136, 130, 127, 
	128, 130, 132, 129, 129, 126, 140, 126, 126, 134, 126, 127, 133, 131, 129, 133, 
	126, 125, 134, 130, 129, 127, 128, 137, 127, 124, 131, 132, 128, 128, 130, 133, 
	126, 132, 129, 128, 128, 136, 122, 137, 128, 129, 131, 128, 130, 128, 129, 127, 
	138, 118, 128, 140, 125, 131, 127, 133, 127, 128, 124, 140, 128, 128, 130, 126, 
	140, 117, 142, 124, 133, 127, 127, 136, 124, 130, 129, 129, 129, 127, 131, 128, 
	129, 131, 126, 134, 130, 132, 128, 127, 128, 135, 125, 132, 134, 126, 127, 133, 
	129, 123, 127, 136, 134, 120, 131, 129, 135, 130, 125, 129, 136, 124, 130, 127, 
	132, 132, 128, 131, 131, 126, 131, 127, 131, 127, 130, 140, 123, 128, 124, 133, 
	135, 131, 117, 138, 138, 120, 128, 135, 129, 132, 124, 127, 132, 131, 128, 127, 
	134, 130, 128, 129, 128, 128, 131, 128, 135, 121, 139, 127, 128, 133, 126, 128, 
	134, 131, 127, 124, 131, 133, 123, 131, 131, 135, 125, 127, 130, 138, 126, 125, 
	133, 128, 128, 132, 128, 126, 134, 133, 129, 128, 128, 129, 135, 126, 133, 122, 
	130, 136, 126, 132, 125, 135, 127, 130, 132, 130, 131, 120, 135, 128, 129, 129, 
	130, 130, 124, 133, 125, 134, 125, 132, 129, 124, 134, 129, 125, 134, 129, 126, 
	135, 126, 128, 135, 133, 118, 137, 130, 127, 137, 125, 128, 129, 133, 128, 127, 
	132, 128, 128, 129, 131, 130, 136, 122, 130, 130, 129, 134, 120, 137, 133, 127, 
	127, 128, 136, 128, 129, 128, 132, 125, 131, 132, 130, 126, 132, 134, 123, 132, 
	131, 128, 130, 126, 135, 127, 135, 124, 123, 133, 132, 128, 136, 120, 123, 140, 
	126, 131, 129, 131, 129, 126, 131, 126, 133, 132, 128, 128, 131, 127, 132, 125, 
	131, 130, 132, 123, 127, 137, 129, 129, 128, 126, 130, 132, 128, 131, 129, 127, 
	132, 131, 124, 136, 128, 124, 128, 134, 128, 132, 130, 128, 123, 133, 136, 127, 
	125, 135, 133, 126, 130, 126, 134, 131, 126, 131, 128, 132, 131, 127, 128, 134, 
	128, 128, 131, 125, 137, 128, 123, 130, 130, 132, 130, 130, 124, 128, 134, 131, 
	129, 130, 128, 132, 129, 126, 130, 137, 127, 128, 126, 129, 137, 127, 129, 128, 
	129, 135, 128, 123, 134, 128, 131, 126, 128, 135, 126, 130, 131, 125, 129, 135, 
	127, 125, 130, 130, 128, 129, 129, 129, 128, 128, 128, 129, 128, 128, 131, 128, 
	127, 129, 129, 128, 128, 128, 129, 127, 128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 127, 128, 127, 128, 128, 127
};

