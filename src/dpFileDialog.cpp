#include "dpFileDialog.hpp"

#include "tinyfiledialogs.h"

namespace dp {

	FileDialog::FileDialog() {}
	FileDialog::~FileDialog() {}
	
	void FileDialog::open() {
	
	}
	
	void FileDialog::save() {}

	i8 FileDialog::test() {

		int lIntValue;
		char const * lTmp;
		char const * lTheSaveFileName;
		char const * lTheOpenFileName;
		char const * lTheSelectFolderName;
		char const * lTheHexColor;
		char const * lWillBeGraphicMode;
		unsigned char lRgbColor[3];
		FILE * lIn;
		char lBuffer[1024];
		char lThePassword[1024];
		char const * lFilterPatterns[2] = { "*.txt", "*.text" };

		lWillBeGraphicMode = tinyfd_inputBox("tinyfd_query", NULL, NULL);

#ifdef _MSC_VER
#pragma warning(disable:4996) /* silences warning about strcpy strcat fopen*/
#endif

		if (lWillBeGraphicMode)
		{
			strcpy(lBuffer, "graphic mode: ");
		}
		else
		{
			strcpy(lBuffer, "console mode: ");
		}

		strcat(lBuffer, tinyfd_response);
		strcpy(lThePassword, "tinyfiledialogs v");
		strcat(lThePassword, tinyfd_version);
		tinyfd_messageBox(lThePassword, lBuffer, "ok", "info", 0);

		/*tinyfd_forceConsole = 1;*/
		if (lWillBeGraphicMode && !tinyfd_forceConsole)
		{
			lIntValue = tinyfd_messageBox("Hello World",
				"graphic dialogs [yes] / console mode [no]?",
				"yesno", "question", 1);
			tinyfd_forceConsole = !lIntValue;

			/*lIntValue = tinyfd_messageBox("Hello World",
			"graphic dialogs [yes] / console mode [no]?",
			"yesnocancel", "question", 1);
			tinyfd_forceConsole = (lIntValue == 2);*/
		}

		lTmp = tinyfd_inputBox(
			"a password box", "your password will be revealed", NULL);

		if (!lTmp) return 1;

		/* copy lTmp because saveDialog would overwrites
		inputBox static buffer in basicinput mode */

		strcpy(lThePassword, lTmp);

		lTheSaveFileName = tinyfd_saveFileDialog(
			"let us save this password",
			"passwordFile.txt",
			2,
			lFilterPatterns,
			NULL);

		if (!lTheSaveFileName)
		{
			tinyfd_messageBox(
				"Error",
				"Save file name is NULL",
				"ok",
				"error",
				1);
			return 1;
		}

		lIn = fopen(lTheSaveFileName, "w");
		if (!lIn)
		{
			tinyfd_messageBox(
				"Error",
				"Can not open this file in write mode",
				"ok",
				"error",
				1);
			return 1;
		}
		fputs(lThePassword, lIn);
		fclose(lIn);

		lTheOpenFileName = tinyfd_openFileDialog(
			"let us read the password back",
			"",
			2,
			lFilterPatterns,
			NULL,
			0);

		if (!lTheOpenFileName)
		{
			tinyfd_messageBox(
				"Error",
				"Open file name is NULL",
				"ok",
				"error",
				1);
			return 1;
		}

		lIn = fopen(lTheOpenFileName, "r");

#ifdef _MSC_VER
#pragma warning(default:4996)
#endif

		if (!lIn)
		{
			tinyfd_messageBox(
				"Error",
				"Can not open this file in read mode",
				"ok",
				"error",
				1);
			return(1);
		}
		lBuffer[0] = '\0';
		fgets(lBuffer, sizeof(lBuffer), lIn);
		fclose(lIn);

		tinyfd_messageBox("your password is",
			lBuffer, "ok", "info", 1);

		lTheSelectFolderName = tinyfd_selectFolderDialog(
			"let us just select a directory", NULL);

		if (!lTheSelectFolderName)
		{
			tinyfd_messageBox(
				"Error",
				"Select folder name is NULL",
				"ok",
				"error",
				1);
			return 1;
		}

		tinyfd_messageBox("The selected folder is",
			lTheSelectFolderName, "ok", "info", 1);

		lTheHexColor = tinyfd_colorChooser(
			"choose a nice color",
			"#FF0077",
			lRgbColor,
			lRgbColor);

		if (!lTheHexColor)
		{
			tinyfd_messageBox(
				"Error",
				"hexcolor is NULL",
				"ok",
				"error",
				1);
			return 1;
		}

		tinyfd_messageBox("The selected hexcolor is",
			lTheHexColor, "ok", "info", 1);

		return 0;


	}

}