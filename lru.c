#include <stdio.h>

int findLRU(int time[], int n)
{
    int i, minimum = time[0], pos = 0;

    for (i = 1; i < n; ++i)
    {
        if (time[i] < minimum)
        {
            minimum = time[i];
            pos = i;
        }
    }

    return pos;
}

int main()
{
    int no_of_frames, no_of_pages;
    int frames[10], pages[30], time[10];
    int counter = 0;
    int flag1, flag2;
    int i, j, pos;
    int faults = 0, hits = 0, total_requests = 0;

    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);

    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);

    printf("Enter reference string: ");
    for (i = 0; i < no_of_pages; ++i)
    {
        scanf("%d", &pages[i]);
    }

    /* Initialize frames and time arrays */
    for (i = 0; i < no_of_frames; ++i)
    {
        frames[i] = -1;
        time[i] = 0;
    }

    /* Process each page reference */
    for (i = 0; i < no_of_pages; ++i)
    {
        flag1 = flag2 = 0;

        /* Check for page hit */
        for (j = 0; j < no_of_frames; ++j)
        {
            if (frames[j] == pages[i])
            {
                counter++;
                time[j] = counter;

                flag1 = flag2 = 1;
                hits++;
                total_requests++;
                break;
            }
        }

        /* Check for empty frame */
        if (flag1 == 0)
        {
            for (j = 0; j < no_of_frames; ++j)
            {
                if (frames[j] == -1)
                {
                    counter++;
                    faults++;

                    frames[j] = pages[i];
                    time[j] = counter;

                    flag2 = 1;
                    total_requests++;
                    break;
                }
            }
        }

        /* Replace least recently used page */
        if (flag2 == 0)
        {
            pos = findLRU(time, no_of_frames);

            counter++;
            faults++;

            frames[pos] = pages[i];
            time[pos] = counter;

            total_requests++;
        }

        /* Display current frame status */
        printf("\n");

        for (j = 0; j < no_of_frames; ++j)
        {
            if (frames[j] == -1)
                printf("-\t");
            else
                printf("%d\t", frames[j]);
        }
    }

    /* Display results */
    printf("\n\nTotal Page Faults = %d\n", faults);
    printf("Total Page Hits = %d\n", hits);
    printf("Total Page Requests = %d\n", total_requests);

    float hit_ratio = (float)hits / total_requests;
    float fault_ratio = (float)faults / total_requests;

    printf("Hit Ratio = %.2f\n", hit_ratio);
    printf("Fault Ratio = %.2f\n", fault_ratio);

    return 0;
}