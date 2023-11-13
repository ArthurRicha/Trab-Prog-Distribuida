void compute(int total_count, int my_count, float my_points[][3]) {
  // total_count is the total number of points
  // my_count is the number of points for this process
  // my_points is a float table of shape [my_count][3]

  // 1- Sum over all the points in local_sum
  float local_sum[3] = {0.0f, 0.0f, 0.0f};

  for (int i = 0; i < my_count; ++i) {
    local_sum[0] += my_points[i][0];
    local_sum[1] += my_points[i][1];
    local_sum[2] += my_points[i][2];
  }

  // 2- Reduce the sum of all the points on the variable barycentre 
  float barycentre[3];
  
  MPI_Allreduce(local_sum, barycentre, 3, MPI_FLOAT, MPI_SUM, MPI_COMM_WORLD);

  // 3- Divide every component of the barycentre by the number of points
  barycentre[0] /= total_count;
  barycentre[1] /= total_count;
  barycentre[2] /= total_count;

  // For every point
  for (int i = 0; i < my_count; ++i) {
    float dist = 0.0f;

    // 4- Compute the distance for every point
    dist = sqrt((my_points[i][0] - barycentre[0]) * (my_points[i][0] - barycentre[0]) +
                (my_points[i][1] - barycentre[1]) * (my_points[i][1] - barycentre[1]) +
                (my_points[i][2] - barycentre[2]) * (my_points[i][2] - barycentre[2]));

    // And printing the result
    std::cout << rank << " " << dist << std::endl;
  }
}
