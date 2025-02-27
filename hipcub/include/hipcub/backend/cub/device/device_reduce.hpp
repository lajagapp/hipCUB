/******************************************************************************
 * Copyright (c) 2010-2011, Duane Merrill.  All rights reserved.
 * Copyright (c) 2011-2018, NVIDIA CORPORATION.  All rights reserved.
 * Modifications Copyright (c) 2017-2023, Advanced Micro Devices, Inc.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the NVIDIA CORPORATION nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NVIDIA CORPORATION BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************/

#ifndef HIPCUB_CUB_DEVICE_DEVICE_REDUCE_HPP_
#define HIPCUB_CUB_DEVICE_DEVICE_REDUCE_HPP_

#include "../../../config.hpp"

#include <cub/device/device_reduce.cuh>

BEGIN_HIPCUB_NAMESPACE

class DeviceReduce
{
public:
    template <
        typename InputIteratorT,
        typename OutputIteratorT,
        typename ReduceOpT,
        typename T
    >
    HIPCUB_RUNTIME_FUNCTION static
    hipError_t Reduce(void *d_temp_storage,
                      size_t &temp_storage_bytes,
                      InputIteratorT d_in,
                      OutputIteratorT d_out,
                      int num_items,
                      ReduceOpT reduction_op,
                      T init,
                      hipStream_t stream = 0,
                      bool debug_synchronous = false)
    {
        (void)debug_synchronous;
        return hipCUDAErrorTohipError(::cub::DeviceReduce::Reduce(d_temp_storage,
                                                                  temp_storage_bytes,
                                                                  d_in,
                                                                  d_out,
                                                                  num_items,
                                                                  reduction_op,
                                                                  init,
                                                                  stream));
    }

    template <
        typename InputIteratorT,
        typename OutputIteratorT
    >
    HIPCUB_RUNTIME_FUNCTION static
    hipError_t Sum(void *d_temp_storage,
                   size_t &temp_storage_bytes,
                   InputIteratorT d_in,
                   OutputIteratorT d_out,
                   int num_items,
                   hipStream_t stream = 0,
                   bool debug_synchronous = false)
    {
        (void)debug_synchronous;
        return hipCUDAErrorTohipError(::cub::DeviceReduce::Sum(d_temp_storage,
                                                               temp_storage_bytes,
                                                               d_in,
                                                               d_out,
                                                               num_items,
                                                               stream));
    }

    template <
        typename InputIteratorT,
        typename OutputIteratorT
    >
    HIPCUB_RUNTIME_FUNCTION static
    hipError_t Min(void *d_temp_storage,
                   size_t &temp_storage_bytes,
                   InputIteratorT d_in,
                   OutputIteratorT d_out,
                   int num_items,
                   hipStream_t stream = 0,
                   bool debug_synchronous = false)
    {
        (void)debug_synchronous;
        return hipCUDAErrorTohipError(::cub::DeviceReduce::Min(d_temp_storage,
                                                               temp_storage_bytes,
                                                               d_in,
                                                               d_out,
                                                               num_items,
                                                               stream));
    }

    template <
        typename InputIteratorT,
        typename OutputIteratorT
    >
    HIPCUB_RUNTIME_FUNCTION static
    hipError_t ArgMin(void *d_temp_storage,
                      size_t &temp_storage_bytes,
                      InputIteratorT d_in,
                      OutputIteratorT d_out,
                      int num_items,
                      hipStream_t stream = 0,
                      bool debug_synchronous = false)
    {
        (void)debug_synchronous;
        return hipCUDAErrorTohipError(::cub::DeviceReduce::ArgMin(d_temp_storage,
                                                                  temp_storage_bytes,
                                                                  d_in,
                                                                  d_out,
                                                                  num_items,
                                                                  stream));
    }

    template <
        typename InputIteratorT,
        typename OutputIteratorT
    >
    HIPCUB_RUNTIME_FUNCTION static
    hipError_t Max(void *d_temp_storage,
                   size_t &temp_storage_bytes,
                   InputIteratorT d_in,
                   OutputIteratorT d_out,
                   int num_items,
                   hipStream_t stream = 0,
                   bool debug_synchronous = false)
    {
        (void)debug_synchronous;
        return hipCUDAErrorTohipError(::cub::DeviceReduce::Max(d_temp_storage,
                                                               temp_storage_bytes,
                                                               d_in,
                                                               d_out,
                                                               num_items,
                                                               stream));
    }

    template <
        typename InputIteratorT,
        typename OutputIteratorT
    >
    HIPCUB_RUNTIME_FUNCTION static
    hipError_t ArgMax(void *d_temp_storage,
                      size_t &temp_storage_bytes,
                      InputIteratorT d_in,
                      OutputIteratorT d_out,
                      int num_items,
                      hipStream_t stream = 0,
                      bool debug_synchronous = false)
    {
        (void)debug_synchronous;
        return hipCUDAErrorTohipError(::cub::DeviceReduce::ArgMax(d_temp_storage,
                                                                  temp_storage_bytes,
                                                                  d_in,
                                                                  d_out,
                                                                  num_items,
                                                                  stream));
    }

    template<
        typename KeysInputIteratorT,
        typename UniqueOutputIteratorT,
        typename ValuesInputIteratorT,
        typename AggregatesOutputIteratorT,
        typename NumRunsOutputIteratorT,
        typename ReductionOpT
    >
    HIPCUB_RUNTIME_FUNCTION static
    hipError_t ReduceByKey(void * d_temp_storage,
                           size_t& temp_storage_bytes,
                           KeysInputIteratorT d_keys_in,
                           UniqueOutputIteratorT d_unique_out,
                           ValuesInputIteratorT d_values_in,
                           AggregatesOutputIteratorT d_aggregates_out,
                           NumRunsOutputIteratorT d_num_runs_out,
                           ReductionOpT reduction_op,
                           int num_items,
                           hipStream_t stream = 0,
                           bool debug_synchronous = false)
    {
        (void)debug_synchronous;
        return hipCUDAErrorTohipError(::cub::DeviceReduce::ReduceByKey(d_temp_storage,
                                                                       temp_storage_bytes,
                                                                       d_keys_in,
                                                                       d_unique_out,
                                                                       d_values_in,
                                                                       d_aggregates_out,
                                                                       d_num_runs_out,
                                                                       reduction_op,
                                                                       num_items,
                                                                       stream));
    }
};

END_HIPCUB_NAMESPACE

#endif // HIPCUB_CUB_DEVICE_DEVICE_REDUCE_HPP_
