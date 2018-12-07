#include <TimerOne.h>

void clockISR(void);

#define SENSOR_SIZE 100

struct sensor_S {
    long int tim;
    int value;
} sensorTab[SENSOR_SIZE];
int sensorIx;

long int tick;

void setup() {
    // put your setup code here, to run once:
    tick = 0;
    sensorIx = 0;
    Timer1.initialize(1000); 
    Timer1.attachInterrupt(clockISR); // own pseudoclock based on AVR timer
    Serial.begin(9600);
    pinMode(A0, INPUT);
}

void clockISR(void) {
    tick++;
}

void dumpTable() {
    int i;
    Serial.println(" ---- dump the table ---- ");
    for(i = 0; i < SENSOR_SIZE; i++) {
        Serial.print("sensorTab[");
        Serial.print(i);
        Serial.print("] = { tid = ");
        Serial.print(sensorTab[i].tim);
        Serial.print(" värde = ");
        Serial.print(sensorTab[i].value);
        Serial.println("}");
    }
}

void verifyTable() {
    for(int i = 1; i < SENSOR_SIZE; i++) {
        if(sensorTab[i].value < sensorTab[i-1].value) {
            Serial.print("ERROR: array unsorted at index ");
            Serial.println(i);
        }
    }
}

/*  shellSort: Sorts an array of struct sensor_S by value in ascending order
 *  Sources: https://www.geeksforgeeks.org/shellsort/, https://rosettacode.org/wiki/Sorting_algorithms/Shell_sort
 */
int shellSort(struct sensor_S *arr, int size) {
    // Implementera Shell sort här!
    // The examples I've been looking at are very similar in code, I've chosen to divide by 2, although Marcin Ciura's sequence is probably faster
    int h, i, j;
    struct sensor_S tmp;

    if(!arr || size < 0) return -1; // Function returns int for some reason, so let's use it for something

    // Sort with half the size of the previous gap, starting with half the size of the array
    for(h = size / 2; h > 0; h /= 2)
    {
      for(i = h; i < size; i++)
      {
        tmp = arr[i]; // Move this value to its sorted location (in this gap sequence)
        for(j = i; j >= h && arr[j - h].value > tmp.value; j -= h) // By shifting higher values in gap to the right, consequently making room for the temporary value
        {
          arr[j] = arr[j - h]; // Shift
        }

        arr[j] = tmp; // Temporary value's new, sorted location
      }
    }

    return 0;
}

void loop() {
    // put your main code here, to run repeatedly:
    int sensorVal = analogRead(A0);
    Serial.print("Sensor -- tid = ");
    Serial.print(tick);
    Serial.print(" värde = ");
    Serial.println(sensorVal);
    
    /* I noticed that when i commented out the previous printing lines I got increased performance, so I put this here to make sure the buffer is flushed before going into the sorting, it sped up the time reported by about 5-6 times (~35ms down to ~6ms).
     *  I tried to put it inside the following 'if' statement, just before the sort, but that doubled the time instead for some unknown reason (maybe the flush is processed in another thread that jams sorting? This wasn't an issue if flushing when sensorIx == SENSOR_SIZE - 1).
    */
    //Serial.flush();
    
    sensorTab[sensorIx].tim = tick;
    sensorTab[sensorIx].value = sensorVal;
    sensorIx++;
    if(sensorIx == SENSOR_SIZE) {
        int i, j;
        // dumpTable();
        int time0 = tick;
        Serial.println(" ---- sort the table ---- ");
        int tempIndex = 0;
        // Sätt in sorteringsanrop här:
        shellSort(sensorTab, SENSOR_SIZE);
        int time1 = tick;
        Serial.print("time to sort (ms): ");
        Serial.println(time1-time0);
        verifyTable();
        // dumpTable();
        delay(10000); // 10 seconds
        sensorIx = 0;
    }
    delay(10); // 1/10 second
}
