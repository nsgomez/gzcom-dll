#pragma once
#include "cIGZUnknown.h"
#include <map>

class cISC4Demand;
class SC4Percentage;

class cISC4DemandSimulator : public cIGZUnknown
{
public:
    virtual bool Init() = 0;
    virtual bool Shutdown() = 0;
    virtual uint32_t GetSimulatorType() = 0;

    /**
     * @brief Gets the demand details.
     * @param demand The demand identifier to search for.
     * @param demandIndex The demand identifier index (the upper 4 bytes of the instance ID).
     * @return A cISC4Demand class for the specified type, or NULL if it was not found.
    */
    virtual cISC4Demand* GetDemand(uint32_t demandID, uint32_t demandIndex) = 0;
    virtual void UpdateOccupantEffects(SC4Percentage unknown1, SC4Percentage const& unknown2, SC4Percentage const& unknown3) = 0;

    /**
     * @brief Calculates the available jobs per unit of demand.
     * @param jobsArray An array of 3 float values.
     * @param demand The demand identifier to search for.
     * @param demandIndex The demand identifier index (the upper 4 bytes of the instance ID).
    */
    virtual void CalculateJobsPerUnitOfDemand(float* jobsArray, uint32_t demandID, uint32_t demandIndex) = 0;

    /**
     * @brief Gets the number of jobs by census type.
     * @param type The census type
     * @return The number of jobs by census type.
    */
    virtual uint32_t GetJobsBySensus(uint32_t type) = 0;

    /**
     * @brief Gets the neutral tax rate.
     * @return The neutral tax rate.
    */
    virtual float GetNeutralTaxRate() = 0;
    virtual void GetLocalPopulationSummary(std::map<uint32_t, int32_t>& map) const = 0;
};
