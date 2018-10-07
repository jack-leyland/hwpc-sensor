/*
 * Copyright 2018 University of Lille
 * Copyright 2018 INRIA
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef CSV_H
#define CSV_H

#include <czmq.h>

/*
 * CSV_PATH_BUFFER_SIZE stores the maximum length of a output dir path.
 */
#define CSV_PATH_BUFFER_SIZE 256

/*
 * CSV_LINE_BUFFER_SIZE stores the maximum length of a line in a group csv output file.
 */
#define CSV_LINE_BUFFER_SIZE 512

/*
 * csv_config stores the required information for the module.
 */
struct csv_config
{
    char *sensor_name;
    char *output_dir;
};

/*
 * csv_context stores the context of the module.
 */
struct csv_context
{
    struct csv_config *config;
    zhashx_t *groups_fd; /* char *group_name -> FILE *fd */
    zhashx_t *groups_events; /* char *group_name -> zlistx_t *group_events */
};

/*
 * csv_config_create allocate and set the config struct for the csv module.
 */
struct csv_config *csv_config_create(char *sensor_name, char *output_dir);

/*
 * csv_config_destroy free the allocated resources for the config struct of the csv module.
 */
void csv_config_destroy(struct csv_config *config);

/*
 * csv_create allocate the ressources needed for the module.
 */
struct storage_module *csv_create(struct csv_config *config);

/*
 * csv_destroy free the allocated ressources of the module.
 */
void csv_destroy(struct storage_module *module);

#endif /* CSV_H */

