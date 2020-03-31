ans[k]=0;
    Edge *start = (Edge *)malloc(sizeof(Edge));
    start->cost = 0; start->node = k; push(pq,start);
    while (1) {
        Edge *now = pop(pq);
        if (now == NULL) break;
        int curNode = now->node;
        int curCost = now->cost;
        if (ans[curNode] < curCost) continue;
        Node *cur = adj[curNode];
        while (cur != NULL) {
            Edge *temp = cur->data;
            temp->cost += curCost;
            if (temp->cost < ans[temp->node]) { ans[temp->node] = temp->cost; push(pq, temp); }
            cur = cur->next;
        }
    }