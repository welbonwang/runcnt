
/** run account type
 */
enum runcnt_type {
	RUNCNT_IRQ_ENTRY,
	RUNCNT_IRQ_EXIT,
	RUNCNT_TASK,
};

/** IRQ run account record info
 *
 * @cpu:  cpu core id
 * @type: runcnt_type, RUNCNT_IRQ_ENTRY or RUNCNT_IRQ_EXIT for IRQ
 * @id:   the pid for the first task which is removed from run-queue
 * @resv: set zero or used for MSB 14-bit of total timestamp
 */
struct runcnt_irq {
	uint16_t cpu:2;
	uint16_t id:14;
	uint16_t type:2;
	uint16_t resv:14;
};

/** task run account record info
 *
 * @cpu:  cpu core id
 * @pid:  pid that will be switched from
 * @type: runcnt_type, RUNCNT_TASK
 * @pid2:  pid that will be switched to
 */
struct runcnt_task {
	uint16_t cpu:2;
	uint16_t pid:14;
	uint16_t type:2;
	uint16_t pid2:14;
};

/** run account record
 * @info: information for timestamp
 * @ts: timestamp
 */
struct runcnt {
	union {
		struct runcnt_irq;
		struct runcnt_task;
	} info;
	uint32_t ts;
};
