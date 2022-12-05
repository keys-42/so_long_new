		////////////////////////////////////////////////////////////////////////////
		int i = 0;
		int j;
		while ((*maps)->map[i])
		{
			j = 0;
			while ((*maps)->map[i][j])
			{
				printf("%c", (*maps)->map[i][j]);
				j++;
			}
			i++;
		}
		printf("fd = %d\n", (*maps)->fd);
		printf("hight = %d\n", (*maps)->hight);
		printf("width = %d\n", (*maps)->width);
		printf("wall_head = %d\n", (*maps)->wall_head);
		printf("wall_tail = %d\n", (*maps)->wall_tail);
		printf("player_i = %d\n", (*maps)->player_i);
		printf("player_j = %d\n", (*maps)->player_j);
		printf("exit_i = %d\n", (*maps)->exit_i);
		printf("exit_j = %d\n", (*maps)->exit_j);
		printf("collection_num = %d\n", (*maps)->collection_num);
		 i = 0;
		while ((*maps)->dfs_flag[i])
		{
			j = 0;
			while ((*maps)->dfs_flag[i][j])
			{
				printf("%c", (*maps)->dfs_flag[i][j]);
				j++;
			}
			i++;
		}
		////////////////////////////////////////////////////////////////////////////
