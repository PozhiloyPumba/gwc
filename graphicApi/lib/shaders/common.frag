#version 410 core

layout (location = 0) out vec4 FragColor;

uniform sampler2D tex;
uniform float invResolutionX;
uniform float invResolutionY;

void main()
{
   vec4 t = texture(tex, gl_FragCoord.xy * vec2(invResolutionX, invResolutionY));
   FragColor = vec4(t.xyz, 1.0);
}