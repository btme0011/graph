    for (k = 0; k < V; k++)  
    {  
        // Pick all vertices as source one by one  
        for (i = 0; i < V; i++)  
        {  
            // Pick all vertices as destination for the  
            // above picked source  
            for (j = 0; j < V; j++)  
            {  
                // If vertex k is on the shortest path from  
                // i to j, then update the value of dist[i][j]  
                if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];  
            }  
        }  
    }  

                100
     D---1-- A------B
     |      |      |
     |      |10    |10
     |      |      |
     |--1---C------|
                    
                // try to go from A to B
