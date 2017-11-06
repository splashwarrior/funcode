void* mem_align(int size, uint8_t align)
{
    uint8_t* start = NULL;
    uint8_t fsize = 0;
    uint8_t *start_data = NULL;
    size_t *book_keep = NULL;
    size_t offset = 0;
    if (!align || !size)
	return NULL;
    if (align & (align - 1)) {
	printf("Should be power of 2\n");
	return NULL;
    }
    fsize = size + 2*align + sizeof(size_t);

    start = (uint8_t*)malloc(fsize);
    if (!start) {
	printf("No mem left\n");
	return NULL;
    }
    start_data = start;
    start += sizeof(size_t);

    offset = align - (((size_t)start) % align);

    start += offset;

    book_keep = (size_t*)(start - sizeof(size_t));
    *book_keep = (size_t)start_data;

    printf("start address needs to be aligned orig %x new addr %x\n", start_data, start);
    return (void*)start;
}   

void free_align(uint8_t *start) {
    size_t offset = 0;  

    if (!start) {
	return; 
    }   

    start = (start - sizeof(size_t));
    start = (uint8_t*)(*(size_t*)start);
    printf("Orig Start addr = %x\n", start);
    free(start);
}   

int main(int argc, char *argv[]) {

    int size = 0;
    uint8_t align = 0;
    uint8_t *start = NULL;
    if (argc == 3) { 
	size = atoi(argv[1]);
	align = atoi(argv[2]);
    }
    printf("Size =%d Align=%d\n", size, align);
    if (size < 1) {
	printf("Unknown entries\n");
	return 0;
    }
    start = mem_align(size, align);

    free_align(start);
    printf("Size =%d start=%x align=%d\n", size, start, align);
    return 0;
}   
