#include <stdbool.h>
#include <event2/event.h>
#include <event2/http.h>

#include "tools.h"
#include "stream.h"


struct exposed_t {
	struct picture_t	picture;
	unsigned			width;
	unsigned			height;
	bool				online;
};

struct http_server_runtime_t {
	struct event_base	*base;
	struct evhttp		*http;
	struct stream_t		*stream;
	struct exposed_t	*exposed;
};

struct http_server_t {
	char		*host;
	unsigned	port;

	struct http_server_runtime_t *run;
};


struct http_server_t *http_server_init(struct stream_t *stream);
void http_server_destroy(struct http_server_t *server);

int http_server_listen(struct http_server_t *server);
void http_server_loop(struct http_server_t *server);
void http_server_loop_break(struct http_server_t *server);