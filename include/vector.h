struct Vector;

struct Vector* createVector();

void deleteVector(struct Vector* v);

void setVectorSize(struct Vector* v, int size);

int pushVector(struct Vector* v, char element);

int popVector(struct Vector* v);

void emptyVector(struct Vector* v);

void printVector(struct Vector* v);