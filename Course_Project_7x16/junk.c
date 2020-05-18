int width = 0;
    int height = 0;
    while (tmp)
    {
        if (tmp->index / 10 > height)
        {
            height = tmp->index / 10;
        }
        if (tmp->index % 10 > width)
        {
            width = tmp->index % 10;
        }
        if (tmp->next)
        {
            tmp = tmp->next;
        }
        else
        {
            break;
        }
    }
    float matrix[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            matrix[i][k] = 0;
        }
    }
    while (tmp)
    {
        matrix[tmp->index / 10][tmp->index % 10] = tmp->value;
        if (tmp->next)
        {
            tmp = tmp->next;
        }
        else
        {
            break;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
           printf("%5.5f ",matrix[i][k]); 
        }
        printf("\n");
    }