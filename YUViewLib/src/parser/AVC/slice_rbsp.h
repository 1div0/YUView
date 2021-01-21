/*  This file is part of YUView - The YUV player with advanced analytics toolset
 *   <https://github.com/IENT/YUView>
 *   Copyright (C) 2015  Institut f�r Nachrichtentechnik, RWTH Aachen University, GERMANY
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   In addition, as a special exception, the copyright holders give
 *   permission to link the code of portions of this program with the
 *   OpenSSL library under certain conditions as described in each
 *   individual source file, and distribute linked combinations including
 *   the two.
 *
 *   You must obey the GNU General Public License in all respects for all
 *   of the code used other than OpenSSL. If you modify file(s) with this
 *   exception, you may extend this exception to your version of the
 *   file(s), but you are not obligated to do so. If you do not wish to do
 *   so, delete this exception statement from your version. If you delete
 *   this exception statement from all source files in the program, then
 *   also delete it here.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "NalUnitAVC.h"
#include "parser/common/SubByteReaderLogging.h"
#include "commonMaps.h"

namespace parser::avc
{

class seq_parameter_set_rbsp;
class slice_header;

class slice_layer_without_partitioning_rbsp : public NalRBSP
{
public:
  slice_layer_without_partitioning_rbsp() = default;

  void parse(reader::SubByteReaderLogging &reader,
             SPSMap &                      spsMap,
             PPSMap &                      ppsMap,
             NalType                       nal_unit_type,
             unsigned                      nal_ref_idc,
             std::shared_ptr<slice_header> prev_pic);

  std::shared_ptr<slice_header> sliceHeader;
};

class slice_data_partition_a_layer_rbsp : public NalRBSP
{
public:
  slice_data_partition_a_layer_rbsp() = default;

  void parse(reader::SubByteReaderLogging &reader,
             SPSMap &                      spsMap,
             PPSMap &                      ppsMap,
             NalType                       nal_unit_type,
             unsigned                      nal_ref_idc,
             std::shared_ptr<slice_header> prev_pic);

  std::shared_ptr<slice_header> sliceHeader;
  unsigned                      slice_id{};
};

class slice_data_partition_b_layer_rbsp : public NalRBSP
{
public:
  slice_data_partition_b_layer_rbsp() = default;

  void parse(reader::SubByteReaderLogging &          reader,
             std::shared_ptr<seq_parameter_set_rbsp> partASPS);

  unsigned slice_id{};
  unsigned colour_plane_id{};
  unsigned redundant_pic_cnt{};
};

class slice_data_partition_c_layer_rbsp : public NalRBSP
{
public:
  slice_data_partition_c_layer_rbsp() = default;

  void parse(reader::SubByteReaderLogging &          reader,
             std::shared_ptr<seq_parameter_set_rbsp> partASPS);

  unsigned slice_id{};
  unsigned colour_plane_id{};
  unsigned redundant_pic_cnt{};
};

} // namespace parser::avc
