/*
 * CG Major Project, Monsoon 2015
 * Author: Sarthak Ahuja, 2012088 | IIIT-Delhi
 *
 * Description:
 */

#ifndef SHADER_UTILS_H
#define SHADER_UTILS_H
#include <GL/glew.h>
#include <GL/gl.h>
#include <malloc.h>
char* file_read(const char* filename);
void print_log(GLuint object);
GLuint create_shader(const char* filename, GLenum type);
#endif // SHADER_UTILS_H
