#include "dispatcher.h"
/* 
 * Function used to display the input data.
 * Return: Void
 * Args: struct packet_data_t pointer
 */
int display_message(struct packet_data_t *pdata) {
    uint8_t *str = (uint8_t*) malloc(pdata->msg_len+1);
    if (!str) {
	printf("%s: Out of Memory for string\n", __func__);
	return -ERR_OOM;
    }

    /* copy the message to a local string */
    memcpy(str, pdata->msg_data, pdata->msg_len); 
    /* input data might not be null terminated */
    str[pdata->msg_len] = '\0';

    printf("%s: ASCII string is \"%s\"\n", __func__, str);
    /* Free the local buffer*/
    free(str);

    return NO_ERROR;
}

/* 
 * Function used to display the motor data.
 * Return: Void
 * Args: struct packet_data_t pointer
 */
int update_motor(struct packet_data_t *pdata) {
    float fwd_back, left_right;
    int ret = NO_ERROR;

    /* msg len has to be 8 to read the motor data */
    if (MOTOR_DATA_LEN == pdata->msg_len) {
	fwd_back = *(float *)(pdata->msg_data);
	left_right= *(((float *)pdata->msg_data) + 1);
	printf("%s: update message fwd_back= %f left_right= %f\n", __func__,
		fwd_back, left_right);
    } else {
	printf("%s: update motor has incorrect length\n", __func__);
	ret = -ERR_INV;
    }
    return ret;
}

/*
 * Function used to debug the packet data.
 */
void dump_packet(struct packet_data_t *pdata) {
#if DEBUG
    printf("packet_id=%x\n", pdata->packet_id);
    printf("type=%x\n", pdata->msg_type);
    printf("len=%x\n\n", pdata->msg_len);
#endif
}

int parse_packet(uint8_t * pkt, struct packet_data_t *pdata) {
    int ret = NO_ERROR;
    if (!pdata || !pkt) {
	printf("%s: Invalid input NULL pointer\n", __func__);
	return -ERR_INV;
    }
    /*  Common parsing */
    pdata->packet_id = pkt[0];
    pdata->msg_type = pkt[1];
    /* Assumption is little endian. */
    pdata->msg_len = pkt[2] | pkt[3] << 8;
    pdata->msg_data = &pkt[4];
    
    dump_packet(pdata);
    /* Add new headers here to scale. */
    if (DISPLAY_MSG_HEADER == pdata->msg_type) {
	ret = display_message(pdata);
    } else if (MOTOR_MSG_HEADER == pdata->msg_type) {
	ret = update_motor(pdata);
    } else {
	printf("%s: Invalid header\n", __func__);
	return -ERR_INV;
    }
    return ret;
}

int dispatcher(uint8_t *pkt) {
    struct packet_data_t pdata;
    int ret = NO_ERROR;

    /* Check for null input */
    if (!pkt)
	return -ERR_INV;

    /* Clear the struct before assignment */
    memset(&pdata, 0, sizeof(pdata));
    /*parse the input stream and fill pdata */
    ret = parse_packet(pkt, &pdata);

    return ret;
}
