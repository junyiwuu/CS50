#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            double grey =
                (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;
            image[i][j].rgbtRed = (uint8_t) (grey + 0.5);
            image[i][j].rgbtGreen = (uint8_t) (grey + 0.5);
            image[i][j].rgbtBlue = (uint8_t) (grey + 0.5);
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
            int sumred = 0, sumblue = 0, sumgreen = 0;
            int count = 0;

            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ai = i + di;
                    int aj = j + dj;

                    if (ai >= 0 && ai < height && aj >= 0 && aj < width)
                    {
                        sumred += image[ai][aj].rgbtRed;
                        sumgreen += image[ai][aj].rgbtGreen;
                        sumblue += image[ai][aj].rgbtBlue;
                        count++;
                    }
                }
            }
            copy[i][j].rgbtRed = (uint8_t) ((sumred / (double) (count)) + 0.5);
            copy[i][j].rgbtBlue = (uint8_t) ((sumblue / (double) (count)) + 0.5);
            copy[i][j].rgbtGreen = (uint8_t) ((sumgreen / (double) (count)) + 0.5);
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumredX = 0, sumredY = 0;
            int sumblueX = 0, sumblueY = 0;
            int sumgreenX = 0, sumgreenY = 0;

            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ai = i + di;
                    int aj = j + dj;

                    if (ai >= 0 && ai < height && aj >= 0 && aj < width)
                    {
                        sumredX += image[ai][aj].rgbtRed * gx[di + 1][dj + 1];
                        sumredY += image[ai][aj].rgbtRed * gy[di + 1][dj + 1];

                        sumgreenX += image[ai][aj].rgbtGreen * gx[di + 1][dj + 1];
                        sumgreenY += image[ai][aj].rgbtGreen * gy[di + 1][dj + 1];

                        sumblueX += image[ai][aj].rgbtBlue * gx[di + 1][dj + 1];
                        sumblueY += image[ai][aj].rgbtBlue * gy[di + 1][dj + 1];
                    }
                }
            }
            int sumred = round(sqrt(sumredX * sumredX + sumredY * sumredY));
            int sumblue = round(sqrt(sumblueX * sumblueX + sumblueY * sumblueY));
            int sumgreen = round(sqrt(sumgreenX * sumgreenX + sumgreenY * sumgreenY));

            if (sumred > 255)
            {
                sumred = 255;
            }
            if (sumblue > 255)
            {
                sumblue = 255;
            }
            if (sumgreen > 255)
            {
                sumgreen = 255;
            }
            copy[i][j].rgbtRed = sumred;
            copy[i][j].rgbtBlue = sumblue;
            copy[i][j].rgbtGreen = sumgreen;
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
