#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec3 v_Color;

out vec3 color;

uniform mat4 u_MVP;

void main()
{
    gl_Position = u_MVP * position;
    color = v_Color;
}

#shader fragment
#version 330 core

layout(location = 0) out vec4 fragment;

in vec3 color;

void main()
{
    fragment = vec4(color, 1.0);
}