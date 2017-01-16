struct edge { int to, length; };

int findpath(vector< vector<edge> > &graph, int src, int target)
{
	vector<int> dist(graph.size(), INT_MAX);
	dist[src] = 0;
	set< pair<int,int> > active_vertices;
	active_vertices.insert( {0,src} );

	while(!active_vertices.empty())
	{
		int where = active_vertices.begin()->second;
		if (where == target) return dist[where];
		active_vertices.erase( active_vertices.begin() );
		for (auto edge : graph[where])
			if (dist[edge.to] > dist[where] + edge.length)
			{
				active_vertices.erase( { dist[edge.to], edge.to } );
				dist[edge.to] = dist[where] + edge.length;
				active_vertices.insert( { dist[edge.to], edge.to } );
			}
	}
	return INT_MAX;
}
