/*
 * gvp.h
 *
 *  Created on: September 25, 2013
 *      Author: Siriwat Kasamwattanarote
 */
#pragma once

namespace ins
{

class gvp_space
{

	// Space mode
	const static int OFFSET = 0;
	const static int DEGREE = 1;

	// Parameters
	int _space_mode;
	int _space_size;
	int _gvp_length;
	float _size_per_distance_x;
	float _size_per_distance_y;
	float _size_per_degree;
	float _size_per_distance;
	int total_space;

    // Space score for each dataset
    typedef float tf_score;
    typedef float idf_score;
    typedef unsigned long long ncr_score;
    typedef unordered_map<size_t, tf_score*> _space_tf;                   // dataset_id, if
    typedef unordered_map<size_t, idf_score*> _space_idf;                   // dataset_id, idf
    typedef unordered_map<size_t, ncr_score*> _space_freq;                  // dataset_id, score
    _space_tf space_tf;
    _space_idf space_idf;
    _space_freq space_freq;                                                 // dataset_size is space_freq.size()

    // Iterator
    typedef unordered_map<size_t, tf_score*>::iterator space_tf_iter;
    typedef unordered_map<size_t, idf_score*>::iterator space_idf_iter;
    typedef unordered_map<size_t, ncr_score*>::iterator space_freq_iter;


public:
    gvp_space(void);
    ~gvp_space(void);
    void init_space(const int space_mode = DEGREE, const int space_size = 10, const int gvp_length = 2);
    void add_dataset_feature(const size_t dataset_id);
    void calc_motion(const size_t dataset_id, const float tfidf_in, const float idf_in, const float* dataset_kp, const float* query_kp);
    void get_score(float* &dataset_score);

};

};
//;)
