

void getInput();

typedef struct inputStruct{
char key[34];
char arrow[4];
char space;
} input;

extern input MKT_input;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);