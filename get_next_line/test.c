char *read_file(int fd, char *result) 
{
    if (!result)
        result = ft_calloc(1, 1);

    char *buffer;
    int bytes_read;

	bytes_read = 1;
	*buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    while (bytes_read > 0) 
{
        bytes_read = read_into_buffer(fd, buffer);
        if (bytes_read == -1)
{
            free(buffer);
            return NULL;
}        
        buffer[bytes_read] = '\0';
        result = append_buffer_to_result(result, buffer);
        
        if (buffer_contains_newline(buffer))
            break;
}
    free(buffer);

    if (bytes_read == -1) 
{
        free(result);
        return NULL;
}
	
    return result;
}

int read_into_buffer(int fd, char *buffer) 
{
    return read(fd, buffer, BUFFER_SIZE);
}

char *append_buffer_to_result(char *result, char *buffer) 
{
    return ft_freejoin(result, buffer);
}

int buffer_contains_newline(char *buffer) 
{
    return ft_strchr(buffer, '\n') != NULL;
}

