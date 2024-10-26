#include "helpers.h"
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double newcd;
            newcd = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;
            uint8_t newval = (uint8_t) (newcd + 0.5);
            image[i][j].rgbtBlue = newval;
            image[i][j].rgbtGreen = newval;
            image[i][j].rgbtRed = newval;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double sepiaRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen +
                              .189 * image[i][j].rgbtBlue;
            double sepiaGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen +
                                .168 * image[i][j].rgbtBlue;
            double sepiaBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen +
                               .131 * image[i][j].rgbtBlue;
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            image[i][j].rgbtRed = (uint8_t) (sepiaRed + 0.5);
            image[i][j].rgbtGreen = (uint8_t) (sepiaGreen + 0.5);
            image[i][j].rgbtBlue = (uint8_t) (sepiaBlue + 0.5);
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {

            int swap = width - j - 1;
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][swap];
            image[i][swap] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            int redsum = 0, bluesum = 0, greensum = 0;
            int count = 0;

            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ai = i + di;
                    int aj = j + dj;

                    if (ai >= 0 && ai < height && aj >= 0 && aj < width)
                    {
                        redsum += image[ai][aj].rgbtRed;
                        bluesum += image[ai][aj].rgbtBlue;
                        greensum += image[ai][aj].rgbtGreen;
                        count++;
                    }
                }
            }

            copy[i][j].rgbtRed = (uint8_t) ((redsum) / (double) (count) + 0.5);
            copy[i][j].rgbtGreen = (uint8_t) ((greensum) / (double) (count) + 0.5);
            copy[i][j].rgbtBlue = (uint8_t) ((bluesum) / (double) (count) + 0.5);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }
    return;
}
