#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include <windows.h>


int main()
{
	FILE* pFile = NULL;
	errno_t err = fopen_s(&pFile, "Capybara.bmp", "rb");
	if (err != 0)
	{
		std::cout << "Erreur d'ouverture du fichier";
		return 1;
	}

	//Creation de notre structure de stockage de datas
	BITMAPFILEHEADER fileHeader;
	BITMAPINFOHEADER infoHeader;

	//Remplir les datas
	fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, pFile);
	fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, pFile);

	std::cout << "Largeure " << infoHeader.biWidth << " \nHauteur " << infoHeader.biHeight << " \nBits/pixel " << infoHeader.biBitCount << std::endl;

	//On passe au pixel
	fseek(pFile, fileHeader.bfOffBits, 0);

	//Calculer la taille
	size_t pixelArraySize = infoHeader.biSizeImage;

	//Allocation mémoire
	unsigned char* pixelData = (unsigned char*)malloc(pixelArraySize);

	//Transfer les datas de pFile a pixelData
	fread(pixelData, 1, pixelArraySize, pFile);

	//Fermeture de pFile
	fclose(pFile);

	for (size_t i = 0; i < pixelArraySize; i += 3)
	{
		unsigned char tmp = pixelData[i];
		pixelData[i] = pixelData[i + 2];
		pixelData[i + 2];
	}

	//Creation nouveau fichier
	FILE* pOut = NULL;
	err = fopen_s(&pOut, "NewCapybara.bmp", "wb");

	if (err != 0)
	{
		std::cout << "Erreur dans la création du fichier" << std::endl;
		free(pixelData);
		return 1;
	}

	fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, pOut);
	fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, pOut);

	fwrite(pixelData, 1, pixelArraySize, pOut);

	fclose(pOut);

	free(pixelData);

	std::cout << "Nouveau fichier sauvegarde";

}