//
// Created by KAVOSH on 10/22/2023.
//

#ifndef LC3_ASM_VM_LOADER_H
#define LC3_ASM_VM_LOADER_H
uint16_t swap16(uint16_t x);

void read_image_file(FILE* file);

int read_image(const char* image_path);
#endif //LC3_ASM_VM_LOADER_H
