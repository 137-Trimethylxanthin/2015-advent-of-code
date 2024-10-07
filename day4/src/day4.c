#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>


char *md5_hash(const char *str) {
    MD5_CTX md5;
    unsigned char digest[MD5_DIGEST_LENGTH];
    char *out = (char*)malloc(33); // 32 hex characters + null terminator
    
    MD5_Init(&md5);
    MD5_Update(&md5, str, strlen(str));
    MD5_Final(digest, &md5);
    
    for (int i = 0; i < 16; i++) {
        sprintf(&out[i*2], "%02x", (unsigned int)digest[i]);
    }
    
    return out;
}

int main() {
    const char *input = "iwrupvqb";
    //find the first string that has 5 leading zeros
    int i = 0;
    char *hash;
    while (1) {
        char *input_with_number = (char *)malloc(strlen(input) + 10);
        sprintf(input_with_number, "%s%d", input, i);
        hash = md5_hash(input_with_number);
        if (hash[0] == '0' && hash[1] == '0' && hash[2] == '0' && hash[3] == '0' && hash[4] == '0') {
            break;
        }
        i++;
    }
    printf("The number for 5 0 is %d\n", i);
    while (1) {
                char *input_with_number = (char *)malloc(strlen(input) + 10);
        sprintf(input_with_number, "%s%d", input, i);
        hash = md5_hash(input_with_number);
        if (hash[0] == '0' && hash[1] == '0' && hash[2] == '0' && hash[3] == '0' && hash[4] == '0' && hash[5] == '0') {
            break;
        }
        i++;
    }
    printf("The number for 6 0 is %d\n", i);
    return 0;
}