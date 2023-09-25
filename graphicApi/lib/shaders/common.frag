#version 410 core

layout (location = 0) out vec4 FragColor;

uniform sampler2D tex;

void main()
{
   vec4 t = texelFetch(tex, ivec2(gl_FragCoord.xy), 0);
   FragColor = vec4(t.xyz, 1.0);
}