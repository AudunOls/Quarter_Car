
#include "Quarter_Car.h"


// Quarter_Car constructor
Quarter_Car::Quarter_Car(double unsprung_mass, double sprung_mass, 
    Spring * unsprung_spring_ptr, Spring * sprung_spring_ptr, 
    Damper * unsprung_damper_ptr, Damper * sprung_damper_ptr, 
    Road_Input* road_input_ptr) 
    :unsprung_mass{ unsprung_mass }, sprung_mass{ sprung_mass } 
{
    unsprung_spring = unsprung_spring_ptr;
    sprung_spring = sprung_spring_ptr;
    unsprung_damper = unsprung_damper_ptr;
    sprung_damper = sprung_damper_ptr;
    road_input = road_input_ptr;
}

// Get spring rate functions:
double Quarter_Car::get_unsprung_spring_rate(double spring_extension){
    	return unsprung_spring->get_spring_rate(spring_extension);
}

double Quarter_Car::get_sprung_spring_rate(double spring_extension){
  		return sprung_spring->get_spring_rate(spring_extension);
}

// Get spring forces functions:
double Quarter_Car::get_unsprung_spring_force(double spring_extension) {
    	return unsprung_spring->get_spring_force(spring_extension);
 }
double Quarter_Car::get_sprung_spring_force(double spring_extension){
  		return sprung_spring->get_spring_force(spring_extension);
}


// Get damper coefficient functions:
double Quarter_Car::get_sprung_damper_coefficient(double damper_velocity){
    return sprung_damper->get_damper_coefficent(damper_velocity);
}
double Quarter_Car::get_unsprung_damper_coefficient(double damper_velocity){
    return unsprung_damper->get_damper_coefficent(damper_velocity);
}


// Get damper force functions:
double Quarter_Car::get_sprung_damper_force(double damper_velocity){
    return sprung_damper->get_damper_force(damper_velocity);
}

double Quarter_Car::get_unsprung_damper_force(double damper_velocity){
    return unsprung_damper->get_damper_force(damper_velocity);
}

// Get road velocity:
  double Quarter_Car::get_input(double time){
    return road_input->get_road_velocity(time);
  }

  // Get sprung spring extension
  double Quarter_Car::get_sprung_spring_extension(std::vector<double> state)
  {
      return state[0] - state[2];
  }

  double Quarter_Car::get_unsprung_spring_extension(std::vector<double> state)
  {
      return state[2] - state[4];
  }

  double Quarter_Car::get_sprung_damper_velocity(std::vector<double> state)
  {
      return state[1] - state[3];
  }

  double Quarter_Car::get_unsprung_damper_velocity(std::vector<double> state, double time)
  {
      return state[3] - get_input(time);
  }



  // Set funcitons for spring rates and damper coefficients
  void Quarter_Car::set_unsprung_spring_rates(std::vector<double> spring_rates) {
      unsprung_spring->set_spring_rate(spring_rates);
      return;
  }
  void Quarter_Car::set_sprung_spring_rates(std::vector<double> spring_rates) {
      sprung_spring->set_spring_rate(spring_rates);
      return;
  }




  void Quarter_Car::set_sprung_damper_coefficient(std::vector<double> spring_rates) {
      sprung_damper->set_damper_coefficent(spring_rates);
      return;
  }
  void Quarter_Car::set_unsprung_damper_coefficient(std::vector<double> spring_rates) {
      unsprung_damper->set_damper_coefficent(spring_rates);
      return;
  }


  /* Set paramters sets the parametrs given in the parameter vector
    index 0 is 1x1 vector containing the unsprung mass
    index 1 is a 1x1 vector containing the sprung mass
    index 2 is the unsprung spring rate containing at least 1 element depending on the spring 
    index 3 is the unsprung damper coefficients at leas containing 1 element depending on the damper 
    index 4 is the sprung spring rates containing at least 1 element depending in the spring 
    index 5 is the sprung damper coefficeint containing at least 1 element depending on the damper  
  */

  void Quarter_Car::set_parameters(std::vector<std::vector<double>> parameters){

      unsprung_mass = double(parameters[0][0]);
      sprung_mass = double(parameters[1][0]);
      set_unsprung_spring_rates(parameters[2]);
      set_unsprung_damper_coefficient(parameters[3]);
      set_sprung_spring_rates(parameters[4]);
      set_sprung_damper_coefficient(parameters[5]);
      return;
  };


  // sets the road input by passing the input vec input = [input1, input2]
  void Quarter_Car::set_input(vector<double> input) {
      road_input->set_input(input);
      return;
  }

  std::vector<double> Quarter_Car::get_state_derivatives(double time, std::vector<double> state)
  {
      // Finding the extension and velocities to be used to find rates and coefficients
      double sprung_spring_extension = get_sprung_spring_extension(state);
      double sprung_damper_velocity = get_sprung_damper_velocity(state);

      double unsprung_spring_extension = get_unsprung_spring_extension(state);
      double unsprung_damper_velocity = get_unsprung_damper_velocity(state, time);

      std::vector<double> state_derivatives(5, 0);

      state_derivatives[0] = state[1];
      state_derivatives[1] = (-sprung_spring_extension* get_sprung_spring_rate(sprung_spring_extension)
                             - sprung_damper_velocity* get_sprung_damper_coefficient(sprung_damper_velocity))
                             /sprung_mass;
      state_derivatives[2] = state[3];
      state_derivatives[3] = (sprung_spring_extension * get_sprung_spring_rate(sprung_spring_extension)
                            + sprung_damper_velocity * get_sprung_damper_coefficient(sprung_damper_velocity)
                            - unsprung_spring_extension * get_unsprung_spring_rate(unsprung_spring_extension)
                            - unsprung_damper_velocity * get_unsprung_damper_coefficient(unsprung_damper_velocity))
                            / unsprung_mass;
      state_derivatives[4] = get_input(time);     

      return state_derivatives;
  }


// Gets number of state variables in the quarter car
  int  Quarter_Car::get_number_of_states()
  {
      return number_of_states;
  }

  // Gets number of inputs in quarter car
  int Quarter_Car::get_number_of_inputs() 
  {
      return number_of_inputs;
  }


  std::vector<double> Quarter_Car::analyse_results(std::vector<std::vector<double>> results) {

      std::vector<double> kpi_vec(2,0);

      std::vector<double> z_s = results[0];
      std::vector<double> z_s_dot = results[1];
      std::vector<double> z_u = results[2];
      std::vector<double> z_u_dot = results[3];
      std::vector<double> z_r = results[4];
      std::vector<double> z_r_dot = results[5];


      std::vector<double> z_s_ddot = results[7];
      std::vector<double> z_u_ddot = results[9];


      double rms_sprung_accs = calculate_rms(z_s_ddot);
      double rms_unsprung_accs = calculate_rms(z_u_ddot);
        
      kpi_vec[0] = rms_sprung_accs;
      kpi_vec[1] = rms_unsprung_accs;

      return kpi_vec;

  };



  double Quarter_Car::calculate_rms(std::vector <double> vec) {

      int n = int(vec.size());

      double square{ 0.0 };
      double mean{ 0.0 }, root{ 0.0 };


      // Calculate square.
      for (int i = 0; i < n; i++) {
          square += pow(vec[i], 2);
      }

      // Calculate Mean.
      mean = (square / (double)(n));

      // Calculate Root.
      root = sqrt(mean);

      return root;

  };


  void Quarter_Car::plot(std::vector <std::vector<double>> results) {

      vector<double> time = results[12];

      /********** Sprung mass position **********/

      Plot2D plot_x1;

      // Set the x and y labels
      plot_x1.xlabel("Time [s]");
      plot_x1.ylabel("Position [m]");
      plot_x1.legend().hide();

      // Plot states
      plot_x1.drawCurve(time, results[0]);
 


      /********** Sprung mass velocity **********/

      Plot2D plot_x2;

      // Set the x and y labels
      plot_x2.xlabel("Time [s]");
      plot_x2.ylabel("Velocity [m/s]");
      plot_x2.legend().hide();

      // Plot states
      plot_x2.drawCurve(time, results[1]);


      /********** Unsprung mass position **********/

      Plot2D plot_x3;

      // Set the x and y labels
      plot_x3.xlabel("Time [s]");
      plot_x3.ylabel("Position [m]");
      plot_x3.legend().hide();

      // Plot states
      plot_x3.drawCurve(time, results[2]);


      /********** Unsprung mass velocity **********/


      Plot2D plot_x4;

      // Set the x and y labels
      plot_x4.xlabel("Time [s]");
      plot_x4.ylabel("Velocity [m/s]");
      plot_x4.legend().hide();

      // Plot states
      plot_x4.drawCurve(time, results[3]);

      /* Road position */

      Plot2D plot_x5;

      // Set the x and y labels
      plot_x5.xlabel("Time [s]");
      plot_x5.ylabel("Position [m]");
      plot_x5.legend().hide();

      plot_x5.drawCurve(time, results[4]);

      /* Road velocity */

      Plot2D plot_x6;

      // Set the x and y labels
      plot_x6.xlabel("Time [s]");
      plot_x6.ylabel("Velocity [m/s]");
      plot_x6.legend().hide();

      // Plot states
      plot_x6.drawCurve(time, results[5]);



      Figure fig_all = { {plot_x1, plot_x2},
                         {plot_x3, plot_x4},
                         {plot_x5, plot_x6} };

      //fig_all.title("Quarter Car Simulation");

      // Create canvas to hold figure
      Canvas canvas_all = { {fig_all} };
      canvas_all.size(749, 1500);

      canvas_all.show();

      
      /************** Plot of accelerations ****************/
      
      Plot2D plot_x8;

      // Set the x and y labels
      plot_x8.xlabel("Time, [s]");
      plot_x8.ylabel("Sprung Acceleration [m/s^2]");

      // Set the legend to be on the bottom along the horizontal
      plot_x8.legend().hide();

      // Plot states
      plot_x8.drawCurve(time, results[7]);



      Plot2D plot_x10;

      // Set the x and y labels
      plot_x10.xlabel("Time, [s]");
      plot_x10.ylabel("Unsprung Acceleration [m/s^2]");

      // Set the legend to be on the bottom along the horizontal
      plot_x10.legend().hide();

      // Plot states
      plot_x10.drawCurve(time, results[9]);



      Figure fig_accs = { {plot_x8, plot_x10} };

      fig_accs.title("Acceleration");

      // Create canvas to hold figure
      Canvas canvas_accs = { {fig_accs} };
      canvas_accs.size(1000, 500);

      canvas_accs.show();

      

      return;

  }

  /************** sweep parameters *************/
   // Sweep parameters plots the results obtained in the simulation function sweep_parameters()
   // the function takes in a 3D vector the length of number of sweeps. Each of the sweeps contain the results from one 
   // entire simulation.
void Quarter_Car::sweep_parameters(std::vector<std::vector<std::vector<double> > > results_matrix){
      
    
    int n_sweeps{ int(results_matrix.size()) };
    vector<double> time_vector = results_matrix[0][12];
    int n = int(time_vector.size() - 1);

      vector<vector<double>> z_s(n_sweeps, vector<double>(n + 1, 0));
      vector<vector<double>> z_s_dot(n_sweeps, vector<double>(n + 1, 0));
      vector<vector<double>> z_u(n_sweeps, vector<double>(n + 1, 0));
      vector<vector<double>> z_u_dot(n_sweeps, vector<double>(n + 1, 0));
      vector<vector<double>> z_r(n_sweeps, vector<double>(n + 1, 0));
      vector<vector<double>> z_r_dot(n_sweeps, vector<double>(n + 1, 0));
      vector<vector<double>> z_s_ddot(n_sweeps, vector<double>(n + 1, 0));
      vector<vector<double>> z_u_ddot(n_sweeps, vector<double>(n + 1, 0));

      // Initialize plots
      Plot2D plot_z_s;
      Plot2D plot_z_s_dot;
      Plot2D plot_z_u;
      Plot2D plot_z_u_dot;
      Plot2D plot_z_r;
      Plot2D plot_z_r_dot;
      Plot2D plot_z_s_ddot;
      Plot2D plot_z_u_ddot;
      Plot2D plot_sprung_KPI;
      Plot2D plot_unsprung_KPI;
      Plot2D plot_sprung_kpi;
      Plot2D plot_unsprung_kpi;

      vector<double> kpi_vec{ 0,0 };
      vector<double> kpi_sprung(n_sweeps, 0);
      vector<double> kpi_unsprung(n_sweeps, 0);
      vector<int> iterations_vec(n_sweeps, 0);
      vector<double> kpi_sprung_vec{ 0 };

      for (int i = 0; i < n_sweeps; i++) {

          // Storing result i in results vectors for each state
          z_s[i] = results_matrix[i][0];
          z_s_dot[i] = results_matrix[i][1];
          z_u[i] = results_matrix[i][2];
          z_u_dot[i] = results_matrix[i][3];
          z_r[i] = results_matrix[i][4];
          z_r_dot[i] = results_matrix[i][5];
          z_s_ddot[i] = results_matrix[i][7];
          z_u_ddot[i] = results_matrix[i][9];

          // getting sprung and unsprung KPIs
          kpi_vec = analyse_results(results_matrix[i]);
          kpi_sprung[i] = kpi_vec[0];
          kpi_unsprung[i] = kpi_vec[1];


          // Drawing all the plots of iteration i
          string label_string = to_string(i + 1);
          plot_z_s.drawCurve(time_vector, z_s[i]).label(label_string);
          plot_z_s_dot.drawCurve(time_vector, z_s_dot[i]).label(label_string);
          plot_z_u.drawCurve(time_vector, z_u[i]).label(label_string);
          plot_z_u_dot.drawCurve(time_vector, z_u_dot[i]).label(label_string);
          plot_z_r.drawCurve(time_vector, z_r[i]).label(label_string);
          plot_z_r_dot.drawCurve(time_vector, z_r_dot[i]).label(label_string);
          plot_z_s_ddot.drawCurve(time_vector, z_s_ddot[i]).label(label_string);
          plot_z_u_ddot.drawCurve(time_vector, z_u_ddot[i]).label(label_string);

          // Creating the iteration vector
          iterations_vec[i] = i + 1;
      }

      // Sprung mass KPI plot settings
      plot_sprung_kpi.drawBoxes(iterations_vec, kpi_sprung);
      plot_sprung_kpi.boxWidthRelative(0.5);
      plot_sprung_kpi.yrange(0.0, 5.0);
      plot_sprung_kpi.xrange(0.0, (n_sweeps + 1));
      plot_sprung_kpi.xlabel("Iterations");
      plot_sprung_kpi.ylabel("Sprung Mass KPI");
      plot_sprung_kpi.legend().hide();


      // Unsprung mass KPI plot settings
      plot_unsprung_kpi.drawBoxes(iterations_vec, kpi_unsprung);
      plot_unsprung_kpi.boxWidthRelative(0.5);
      plot_unsprung_kpi.yrange(0.0, 5.0);
      plot_unsprung_kpi.xrange(0.0, (n_sweeps + 1));
      plot_unsprung_kpi.xlabel("Iterations");
      plot_unsprung_kpi.ylabel("Unprung Mass KPI");
      plot_unsprung_kpi.legend().hide();

      // Create figure to hold KPI plot
      Figure fig_kpi = { {plot_sprung_kpi}, {plot_unsprung_kpi} };

      // Create canvas to hold figure
      Canvas canvas_kpi = { {fig_kpi} };
      canvas_kpi.size(749, 749);
      canvas_kpi.show();


      // Setting x and y labels for the plots
      plot_z_s.xlabel("Time [s]");
      plot_z_s.ylabel("Sprung mass position [m]");
      plot_z_s_dot.xlabel("Time [s]");
      plot_z_s_dot.ylabel("Sprung mass velocity [m/s]");
      plot_z_u.xlabel("Time [s]");
      plot_z_u.ylabel("Unsprung mass position [m]");
      plot_z_u_dot.xlabel("Time [s]");
      plot_z_u_dot.ylabel("Unsprung mass velocity [m/s]");
      plot_z_r.xlabel("Time [s]");
      plot_z_r.ylabel("Road position [m]");
      plot_z_r_dot.xlabel("Time [s]");
      plot_z_r_dot.ylabel("Road velocity [m/s]");
      plot_z_s_ddot.xlabel("Time [s]");
      plot_z_s_ddot.ylabel("Sprung accelearation [m/s^2]");
      plot_z_u_ddot.xlabel("Time [s]");
      plot_z_u_ddot.ylabel("Unsprung acceleration [m/s]");


      // Fixing legend position
      plot_z_s.legend().hide();
      plot_z_s_dot.legend().hide();
      plot_z_u.legend().hide();
      plot_z_u_dot.legend().hide();
      plot_z_r.legend().hide();
      plot_z_r_dot.legend().hide();
      plot_z_s_ddot.legend().atOutsideBottom().displayHorizontal();
      plot_z_u_ddot.legend().atOutsideBottom().displayHorizontal();


      // Create figures to hold plots
      Figure fig_z_s = { {plot_z_s} };
      fig_z_s.title("Sprung mass position");
      Figure fig_z_s_dot = { {plot_z_s_dot} };
      fig_z_s_dot.title("Sprung mass velocity");
      Figure fig_z_u = { {plot_z_u} };
      fig_z_u.title("Unsprung mass position");
      Figure fig_z_u_dot = { {plot_z_u_dot} };
      fig_z_u_dot.title("Unsprung mass velocity");
      Figure fig_z_r = { {plot_z_r} };
      fig_z_r.title("Road position");
      Figure fig_z_r_dot = { {plot_z_r_dot} };
      fig_z_r_dot.title("Road velocity");
      Figure fig_z_s_ddot = { {plot_z_s_ddot} };
      fig_z_s_ddot.title("Sprung mass acceleration");
      Figure fig_z_u_ddot = { {plot_z_u_ddot} };
      fig_z_u_ddot.title("Unprung mass acceleration");
      Figure fig_all = { {plot_z_s, plot_z_s_dot},
                     {plot_z_u, plot_z_u_dot},
                     {plot_z_r, plot_z_r_dot},
                      {plot_z_s_ddot, plot_z_u_ddot} };

      // Create canvas to hold figure
      Canvas canvas_all = { {fig_all} };
      canvas_all.size(749, 749);
      canvas_all.show();
  return;
  }




 