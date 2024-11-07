#include "helpers.h"
#include "stdio.h"
#include <string.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    BYTE red; BYTE blue; BYTE green;
    BYTE grayscale;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            red = image[i][j].rgbtRed;
            blue = image[i][j].rgbtBlue;
            green = image[i][j].rgbtGreen;

            grayscale = red * 0.299 + blue * 0.114 + green * 0.587;

            image[i][j].rgbtRed = grayscale;
            image[i][j].rgbtBlue = grayscale;
            image[i][j].rgbtGreen = grayscale;
        } 
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE reflectedImage[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            reflectedImage[i][j] = image[i][width - j];
            
        }
    
    }
    memcpy(image, reflectedImage, sizeof(RGBTRIPLE) * height * width);
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int sumRed;
    int sumBlue;
    int sumGreen;

    for (int i = 1; i < height; i++)
    {
        for (int j = 1 ; j < width; j++)
        {
            sumRed = 0;
            sumBlue = 0;
            sumGreen = 0;

            for (int coll = -1 ; coll < 2; coll++)
            {
                for (int row = -1; row < 2; row++)
                {
                    sumRed += image[i + coll][j + row].rgbtRed;
                    sumBlue += image[i + coll][j +row].rgbtBlue;
                    sumGreen += image[i + coll][j + row].rgbtGreen;
                }
            }
            image[i][j].rgbtRed = sumRed / 9;
            image[i][j].rgbtBlue = sumBlue / 9;
            image[i][j].rgbtGreen = sumGreen / 9;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int GxBlue = 0; int GyBlue = 0; int GxRed = 0; int GyRed = 0; int GxGreen = 0; int GyGreen = 0;
    int blue = 0; int red = 0; int green = 0;
    int sobelOperatorX[3][3] = 
    {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };
    int sobelOperatorY[3][3] =
    {
        {-1, -2, -1},
        {0 , 0, 0},
        {1 , 2, 1}
    };
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            GxBlue = GxRed = GxGreen = GyBlue = GyRed = GyGreen = blue = red = green = 0;
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    GxBlue += sobelOperatorX[x][y] * image[i + x][j + y].rgbtBlue;
                    GxRed += sobelOperatorX[x][y] * image[i + x][j + y].rgbtRed;
                    GxGreen += sobelOperatorX[x][y] * image[i + x][j + y].rgbtGreen;

                    GyBlue += sobelOperatorY[x][y] * image[i + x][j + y].rgbtBlue;
                    GyRed += sobelOperatorY[x][y] * image[i + x][j + y].rgbtRed;
                    GyGreen += sobelOperatorY[x][y] * image[i + x][j + y].rgbtGreen;
                }
            }

            blue = (int) sqrt(GxBlue * GxBlue + GyBlue * GyBlue);
            red = (int) sqrt(GxRed * GxRed + GyRed * GyRed);
            green = (int) sqrt(GxGreen * GxGreen + GyGreen * GyGreen);

            if (blue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else if (blue < 0)
            {
                image[i][j].rgbtBlue = 0;
            }
            else
            {
                image[i][j].rgbtBlue = blue;
            }
            if (red > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else if (red < 0)
            {
                image[i][j].rgbtRed = 0;
            }
            else
            {
                image[i][j].rgbtRed = red;
            }
            if (green > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else if (green< 0)
            {
                image[i][j].rgbtGreen = 0;
            }
            else
            {
                image[i][j].rgbtGreen = green;
            }
        }
    }
    return;
}

void invert (int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = 255 - image[i][j].rgbtRed;
            image[i][j].rgbtBlue = 255 - image[i][j].rgbtBlue;
            image[i][j].rgbtGreen = 255 - image[i][j].rgbtGreen;
        }
    }
    return;
}