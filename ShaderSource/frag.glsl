#version 410 core

out vec4 FragColor;

in vec3 pPos;

vec3 Normalize(vec3 pos)
{
    normalize(pos);
    pos /= 2.0f;
    pos += 0.5f;

    return pos;
}

void main()
{
    FragColor = vec4(Normalize(pPos),1.0);
}
