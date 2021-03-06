
#include "SMPSInput.hpp"
#include "CbcLagrangeSolver.hpp"
#include "ScipLagrangeSolver.hpp"
#include "CbcRecourseSolver.hpp"
#include "conicBundleParDriver1.hpp"

using namespace std;


int main(int argc, char **argv) {

	
	MPI_Init(&argc, &argv);

	int mype;
	MPI_Comm_rank(MPI_COMM_WORLD,&mype);

	if (argc != 2) {
		if (mype == 0) printf("Usage: %s [SMPS root name]\n",argv[0]);
		return 1;
	}

	string smpsrootname(argv[1]);

	SMPSInput input(smpsrootname+".cor",smpsrootname+".tim",smpsrootname+".sto");

	conicBundleParDriver1<ScipLagrangeSolver,CbcRecourseSolver>(input);

	MPI_Finalize();

	return 0;

}
