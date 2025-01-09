/* Statistical analysis
Mean, standard deviation and correlation
*/
#include <stdio.h>
#include <math.h>

int length = 5;
float arr[5][2];
int i;

int main()
{
	  // Get array elements from the user
  printf("Enter five pairs of float numbers, two in each line seperated by a space:\n");
  for (i = 0; i < length; i++) {
    printf("Array pair %d: ", i + 1);
    scanf("%f%f", &arr[i][0], &arr[i][1]);
  }

	printf("arr:\n");
	for (i = 0; i < length; ++i)
	{
		printf("%.2f %.2f\n", arr[i][0], arr[i][1]);
	}

	// find sample mean of x and y
	float sumX = 0, sumY = 0;

	for (i = 0; i < length; ++i)
	{
		sumX += arr[i][0];
		sumY += arr[i][1];
	}

	float meanX = sumX / length, meanY = sumY / length;

	printf("Mean of X is %.2f, Mean of Y is %.2f\n", meanX, meanY);
	float var2X = 0, var2Y = 0;

	for (i = 0; i < length; ++i)
	{
		float varX = (arr[i][0] - meanX);
		var2X += varX * varX;
		float varY = (arr[i][1] - meanY);
		var2Y += varY * varY;
	}

	// sample standard deviation (n-1) not population standard deviation
	float stdevX = sqrt(var2X / (length - 1)), stdevY = sqrt(var2Y / (length - 1));

	printf("Standard deviation of X is %.2f, Standard deviation of Y is %.2f\n", stdevX, stdevY);
	float rSum = 0;
	for (i = 0; i < length; ++i)
	{
		float xScore = (arr[i][0] - meanX) / stdevX;
		float yScore = (arr[i][1] - meanY) / stdevY;
		rSum += xScore * yScore;
	}

	float r = rSum / (length - 1);
	printf("Correlation is %.2f\n", r);
}
