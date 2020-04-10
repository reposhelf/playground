tuktuk_server: tuktuk_server.c
	gcc -g -Wall tuktuk_server.c -Inetstream/include \
		-Lnetstream/lib -lnetstream -o tuktuk_server

advice_server: advice_server.c
	gcc -g -Wall advice_server.c -Inetstream/include \
		-Lnetstream/lib -lnetstream -o advice_server

wiki_client: wiki_client.c
	gcc -g -Wall wiki_client.c -o wiki_client

clean:
	rm -f *~ *.o tuktuk_server advice_server wiki_client
