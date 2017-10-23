#pragma once

inline dynIntArr readIntArr()
{
	if (isConcoleRead())
		return consoleReadInt();

	return fileReadInt(INPUT_FILE_NAME);
}
