#shader vertex
#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec4 v_Color;

out vec4 color;

uniform mat4 u_MVP;

void main()
{
    gl_Position = u_MVP * vec4(position, 1.0f);
    color = v_Color;
}

#shader fragment
#version 330 core

layout(location = 0) out vec4 fragment;

in vec4 color;

void main()
{
    fragment = color;
}