#version 330

in highp vec2 coordTexture;

uniform sampler2D text;
uniform float alpha_threshold;
uniform bool hovered;
uniform float yOffset;

out highp vec4 fColor;

void main()
{
    vec2 coords = vec2(coordTexture.x, coordTexture.y + yOffset);
    vec4 color = texture(text, coords);
    if (color.a <= alpha_threshold) // Or whichever comparison here
        discard;

    float colorHover = 0.1f;

    if (!hovered) {
        colorHover = 0.0f;
    }
    fColor = vec4(color.x + colorHover, color.y + colorHover, color.z +
        colorHover, color.w);
}
