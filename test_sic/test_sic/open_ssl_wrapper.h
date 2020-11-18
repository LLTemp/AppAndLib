//
//  open_ssl_wrapper.h
//  test_sic
//
//  Created by SergeyBrazhnik on 12.11.2020.
//

#ifndef open_ssl_wrapper_h
#define open_ssl_wrapper_h

#include <stdio.h>
int aes_cfb8_nopadding(
        const unsigned char aeskey[],
        const unsigned char iv[],
        const unsigned char body[],
        int body_length,
        unsigned char out[]);

#endif /* open_ssl_wrapper_h */
