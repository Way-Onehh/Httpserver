#http测试
HTTPTEST:$(http.test)
	./sh/test.sh $(BIN)/HTTPTEST
	$(CC) $^ -o $(BIN)/$@  

$(http.test):%.o:%.cpp
	$(CC) $(FLAG) -c $^ -o $(TEMP)/$@
