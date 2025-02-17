void lex(char* tokenBuffer[], char* fileBuffer){
	char* token;
	int fileBufferLength = strlen(fileBuffer);
	int j = 0;
	for(int i = 0; i <= fileBufferLength; i++){
		if(isToken(token)){
			tokenBuffer[j] = token;
			token = "";
		}
		strncat(token, tokenBuffer[i], 1);
	}
}

bool isToken(char* string){
	int stringLength = strlen(string);
	char* endOfLine = ";";
	char* whiteSpace = " ";
	char terminator = 0;
	if(string == endOfLine){
		return true;
	}else if(string == whiteSpace){
		string[stringLength] = terminator;
		return true;
	}
	return false;
}
