#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNor;
layout (location = 2) in vec2 aTex;
layout (location = 3) in vec4 aCol;
layout (location = 4) in vec3 aTan;
layout (location = 5) in vec3 aBit;

layout (std140) uniform Matrices
{
    mat4 projection;
    mat4 view;
};

uniform mat4 model;

out VS_OUT
{
	vec3 FragPos;
    vec3 FragNor;
	vec2 FragTex;
	
	mat3 TBN;
} vs_out;


void main()
{
	vs_out.FragTex = aTex;

    gl_Position = projection * view * model * vec4(aPos, 1.0);
}