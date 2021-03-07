#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>

char hostapd_record[100][50], dhcp_record[100][50];
int hostapd_record_count, dhcp_record_count;

void read_hostapd_record() {
    FILE *fptr;
    fptr = fopen("/home/manh/ub2021/netlab/agent-controller/hostapd_authenticate_log", "r");
    hostapd_record_count = -1;
    while (fgets(hostapd_record[++hostapd_record_count], 100, fptr)) {
        if (strlen(hostapd_record[hostapd_record_count]) == 0) {
            hostapd_record_count--;
            continue;
        }
    }
    fclose(fptr);
}

void read_dhcp_lease_record() {
    FILE *fptr;
    fptr = fopen("/home/manh/ub2021/netlab/agent-controller/dhcp.lease", "r");
    dhcp_record_count = -1;
    while (fgets(dhcp_record[++dhcp_record_count], 100, fptr)) {
        if (strlen(dhcp_record[dhcp_record_count]) == 0) {
            dhcp_record_count--;
            continue;
        }
    }
    fclose(fptr);
}

void consult_qos(char user[]) {
    CURL *curl;
    CURLcode res;
    
    curl = curl_easy_init();
    if(curl) {
        CURL *curl;
        CURLcode res;
        
        curl = curl_easy_init();
        if(curl) {
            curl_easy_setopt(curl, CURLOPT_URL, "google.com");
            /* example.com is redirected, so we tell libcurl to follow redirection */ 
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        
            /* Perform the request, res will get the return code */ 
            res = curl_easy_perform(curl);
            /* Check for errors */ 
            if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        
            /* always cleanup */ 
            curl_easy_cleanup(curl);
        }
    }

}

void main() {
    read_hostapd_record();
    read_dhcp_lease_record();
    // consult_qos("asdb");
}
